#! /bin/sh

HAVE_MARIA=mariadb --version

if [ HAVE_MARIA ]; then
	[ "$UID" -nq 0 ] && echo "To automatically install mariadb you must run this script as root, restart it with root user or install mariadb and run it again after" && exit 1
	DISTRI=cat /etc/*-release
	[ grep "Arch" /etc/*-release ] && pacman -S mariadb
	[ grep "Ubuntu" /etc/*-release ] && apt-get install mariadb-server
	[ grep "Debian" /etc/*-release ] && apt-get install mariadb-server
	[ grep "CentOS" /etc/*-release ] && yum install mariadb-server
	[ grep "Fedora" /etc/*-release ] && dnf install mariadb-server
	[ grep "openSUSE" /etc/*-release] && zypper install mariadb-server
	[ grep "SUSE" /etc/*-release] &&  zypper install mariadb-server
	[ grep "Red Hat" /etc/*-release]  && yum install mariadb-server
	[ grep "Raspbian" /etc/*-release] && apt-get install mariadb-server

	 mysql_install_db --user=mysql --ldata=/var/lib/mysql
	 systemctl start mariadb
fi

DB_NAME="IoC_Extraction "

if [ mariadb -e "SHOW DATABASES LIKE '$DB_NAME'" ]; then
	echo "Database $DB_NAME already exists"
	echo "Do you want to drop it? (y/n)"
	read DROP_DB
	if [ $DROP_DB = "y" ]; then
		mariadb -e "DROP DATABASE $DB_NAME"
		echo "Database $DB_NAME dropped"
	else
		echo "Database $DB_NAME not dropped, this script will exit"
		exit 1
	fi
fi

mariadb -e "CREATE DATABASE $DB_NAME;"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_SHA256 (DATE "

