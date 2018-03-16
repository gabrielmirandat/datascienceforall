## importing data in r1

# import data 1

dir() // lista diretorio atual

path <- file.path("~", "datasets", "states.csv")
data <- read.csv("states.csv", stringsAsFactors = FALSE) // separado virgula
data <- read.delim("states.txt", stringsAsFactors = FALSE) // separado tab
data <- read.table("states2.txt", header=TRUE, sep="/ ou \t", stringsAsFactors = FALSE) // separado por / ou outra coisa

data // printa var
str(data) // printa estrutura da var
summary(data) // info estatistica
head(data) // primeiras seis observacoes

// Select the hot dog with the least calories: lily
lily <- hotdogs[which.min(hotdogs$calories), ]

# import data 2

install.packages("readr")
library(readr)

potatoes_fragment <- read_tsv("potatoes.txt", skip = 6, n_max = 5, col_names = properties)
potatoes <- fread("potatoes.csv")
plot(tasty_potatoes$texture, tasty_potatoes$moistness)

# import data 3

library(readxl)
excel_sheets("cities.xlsx")
read_excel("cities.xlsx")

pop_list <- lapply(excel_sheets("urbanpop.xlsx"),
                   read_excel,
                   path = "urbanpop.xlsx")

pop_a <- read_excel("latitude_nonames.xlsx", sheet=1, col_names=FALSE)

head(urban_pop, n=11)

# import data 4
library(XLConnect)
my_book <- loadWorkbook("urbanpop.xlsx")
class(my_book)

writeWorksheet(my_book,sheet="data_summary",summ)
saveWorkbook(my_book, file ="summary.xlsx")
removeSheet(book, sheet = "Y2010")
saveWorkbook(book, file = "cities4.xlsx")

## importing data in r2

library(DBI)
dbListTables(con)
dbReadTablel(con, "employers")
dbDisconnect(con)
