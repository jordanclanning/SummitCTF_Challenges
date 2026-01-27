
CREATE DATABASE Summit;

USE Summit;

CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(50),
    password VARCHAR(50)
);

INSERT INTO users (username, password) VALUES
('admin','password123'),
('ops','summitops');

CREATE USER 'ctfuser'@'localhost' IDENTIFIED BY 'ctfpass';
GRANT ALL PRIVILEGES ON Summit.* TO 'ctfuser'@'localhost';
FLUSH PRIVILEGES;
EXIT;
