## importing data in r1

# PART1

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

# PART2

install.packages("readr")
library(readr)

potatoes_fragment <- read_tsv("potatoes.txt", skip = 6, n_max = 5, col_names = properties)
potatoes <- fread("potatoes.csv")
plot(tasty_potatoes$texture, tasty_potatoes$moistness)

# PART3

library(readxl)
excel_sheets("cities.xlsx")
read_excel("cities.xlsx")

pop_list <- lapply(excel_sheets("urbanpop.xlsx"),
                   read_excel,
                   path = "urbanpop.xlsx")

pop_a <- read_excel("latitude_nonames.xlsx", sheet=1, col_names=FALSE)

head(urban_pop, n=11)

# PART4
library(XLConnect)
my_book <- loadWorkbook("urbanpop.xlsx")
class(my_book)

writeWorksheet(my_book,sheet="data_summary",summ)
saveWorkbook(my_book, file ="summary.xlsx")
removeSheet(book, sheet = "Y2010")
saveWorkbook(book, file = "cities4.xlsx")

## importing data in r2

# PART1

library(DBI)
dbListTables(con)
dbReadTablel(con, "employers")
dbDisconnect(con)

# PART2
con <- dbConnect(RMySQL::MySQL(), dbname=.., host=.., port=.., user=.., password=..)
subset(employers, subset=started_at > "2012-09-01", select=name)
dbGetQuery(con, "SELECT ..")

res <- dbSendQuery(con, "SELECT..")
dbFetch(res)
dbClearResult(res)

# PART3
read_csv("blabla.csv") // chama http
read_tsv("blabla.txt")

dest_path <- file.path("~", "local_cities.xlxs")
download.file(url, dest_path)
read_excel(dest_path)
load(dest_path)

library(httr)
resp <- GET(url)
raw_content <- content(resp, as="raw")

# PART4
install.packages("jsonlite")
library(jsonlite)

fromJSON("http//...=json")
fromJSON("[1,2,3,4]")
toJSON()

# PART5

library(haven)

SAS: read_sas()
STATA: read_dta() (or read_stata(), which are identical)
SPSS: read_sav() or read_por(), depending on the file type.

SAS
ontime <- read_sas("ontime.sas7bdat")

STATA
ontime <- read_stata("ontimesas7b.dat")
ontime <- read_dta("ontimesas7b.dat")

as_factor(ontime$Airline)
as.character(as_factor(ontime$Airline))

SPSS
read_spss()
	.por->read_por()
	.sav->read_sav(file.path("~", "datasets", "ontime.sav"))



library(foreign)

read.dta(file, convert.factors = TRUE, convert.dates = TRUE, missing.type = FALSE)
read.spss(file, use.value.labels = TRUE, to.data.frame = FALSE)

## cleaning data in R

class(lunch) // get type of data
dim(lunch) // dimension
names(lunch) // get column names

library(dplyr)
glimpse(lunch) // like str

head(lunch, n=15)
tail(lunch, n=15)

hist(lunch$perc_free_red) // histogram
plot(lunch$year, lunch$perc_free_red) // scatter plot

