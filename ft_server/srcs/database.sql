CREATE DATABASE ft_database;
CREATE USER 'tredtusk'@'localhost' IDENTIFIED BY 'tredtusk42';
GRANT ALL PRIVILEGES ON ft_database.* TO 'tredtusk'@'localhost';


FLUSH PRIVILEGES;
