import data 1

dir() // lista diretorio atual

path <- file.path("~", "datasets", "states.csv")
data <- read.csv("states.csv", stringsAsFactors = FALSE) // separado virgula
data <- read.delim("states.txt", stringsAsFactors = FALSE) // separado tab
data <- read.table("states2.txt", header=TRUE, sep="/ ou \t", stringsAsFactors = FALSE) // separado por / ou outra coisa

data // printa var
str(data) // printa var
summary(data) // info estatistica
head(data) // primeiras seis observacoes

// Select the hot dog with the least calories: lily
lily <- hotdogs[which.min(hotdogs$calories), ]

