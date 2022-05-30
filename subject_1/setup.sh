#! /bin/sh

ls /bin/ | grep mariadb
if [ $? -ne 0 ]; then
	[ "$UID" -ne 0 ] && echo -e "To automatically install mariadb you must run this script as root, restart it with root user or install mariadb and run it again after\n Current UID: $UID" && exit 1
	grep "Arch" /etc/*-release && pacman -S mariadb --noconfirm
	grep "Ubuntu" /etc/*-release && apt-get install mariadb-server -y
	grep "Debian" /etc/*-release && apt-get install mariadb-server -y
	grep "CentOS" /etc/*-release && yum install mariadb-server -y
	grep "Fedora" /etc/*-release && dnf install mariadb-server -y
	grep "openSUSE" /etc/*-release&& zypper install mariadb-server -y
	grep "SUSE" /etc/*-release &&  zypper install mariadb-server -y
	grep "Red Hat" /etc/*-release && yum install mariadb-server -y
	grep "Raspbian" /etc/*-release && apt-get install mariadb-server -y

	mysql_install_db --user=mysql --ldata=/var/lib/mysql
	systemctl start mariadb
fi

DB_NAME="IoC_Extraction"

if mariadb -e "SHOW DATABASES LIKE '$DB_NAME'"; then
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

USERNAME=EML
PASSWORD=EML_PARSE

mariadb -e "CREATE DATABASE $DB_NAME;"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_SHA256 (DATE varchar(128), TIME varchar(128),256SUM varchar(128))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_IPV4 (DATE varchar(128), TIME varchar(128),256SUM varchar(128), IPV4 varchar(64))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_IPV6 (DATE varchar(128), TIME varchar(128),256SUM varchar(128), IPV6 varchar(64))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_DOMAIN (DATE varchar(128), TIME varchar(128),256SUM varchar(128), DOMAIN varchar(256))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_MIME_Version (DATE varchar(128), TIME varchar(128),256SUM varchar(128), MIME_Version varchar(64))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_Email_Add_ress (DATE varchar(128), TIME varchar(128),256SUM varchar(128), EMAIL varchar(256))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_Date (DATE varchar(128), TIME varchar(128),256SUM varchar(128))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_SMTP_ID (DATE varchar(128), TIME varchar(128),256SUM varchar(128), SMTPid varchar(64))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_Subject (DATE varchar(128), TIME varchar(128),256SUM varchar(128), Subject varchar(512))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_Content_Type (DATE varchar(128), TIME varchar(128),256SUM varchar(128), Content_Type varchar(256))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_Boundary (DATE varchar(128), TIME varchar(128),256SUM varchar(128), Boundary varchar(256))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_Email_Body (DATE varchar(128), TIME varchar(128),256SUM varchar(128), Body_encoded text(16384))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_Attachment (DATE varchar(128), TIME varchar(128),256SUM varchar(128), Content_type varchar(256), Content_disposition varchar(256))"
mariadb -e "USE $DB_NAME; CREATE TABLE EML_Message_ID (DATE varchar(128), TIME varchar(128),256SUM varchar(128), Message_ID varchar(64))"

mariadb -e "CREATE USER '$USERNAME'@'localhost' IDENTIFIED BY '$PASSWORD';"
mariadb -e "GRANT ALL PRIVILEGES ON $DB_NAME . * TO '$USERNAME'@'localhost';"
mariadb -e "FLUSH PRIVILEGES;"

echo "Default User: $USERNAME"
echo "Default Password: $PASSWORD"
