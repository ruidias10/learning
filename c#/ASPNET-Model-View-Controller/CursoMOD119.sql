/*
Comentario de várias linhas
*/

CREATE DATABASE [CursoMOD119];

USE "CursoMOD119";

CREATE TABLE Artigo (
	id				 INT PRIMARY KEY IDENTITY(1,1), -- AUTO_INCREMENT
	nome             VARCHAR(255) NOT NULL,
	preco            MONEY,                         -- (DOUBLE)
	dataCriacao      DATE NOT NULL,
	descontinuado    BIT NOT NULL,                  -- (BOOLEAN)
);