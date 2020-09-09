FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade

RUN apt-get install -y vim
RUN apt-get install -y nginx 
RUN apt-get install -y default-mysql-server php7.3 php7.3-fpm 
RUN apt-get install -y wordpress
RUN apt-get install -y php7.3-mysql php-json php-mbstring 
RUN apt-get install -y openssl


ADD https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz phpmyadmin.tar.gz
RUN tar xvzf phpmyadmin.tar.gz && mv phpMyAdmin-5.0.2-all-languages /var/www/html/phpmyadmin
RUN mv /usr/share/wordpress /var/www/html

COPY ./srcs/default /etc/nginx/sites-available/default
COPY ./srcs/server.crt /etc/ssl/certs/server.crt 
COPY ./srcs/server.key /etc/ssl/private/server.key
COPY ./srcs/autoindex.sh /

COPY ./srcs/wp-config.php /var/www/html/wordpress
COPY ./srcs/config.inc.php /var/www/html/phpmyadmin/

COPY ./srcs/database.sql /var/
COPY ./srcs/start.sh /


RUN chown -R www-data /var/www/html
# RUN chmod -R 777 /var/www/
# RUN chmod +x start.sh
# RUN chown -R www-data:www-data /var/www/html

EXPOSE 80 443



ENTRYPOINT bash start.sh
