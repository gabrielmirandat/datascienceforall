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

plot(tasty_potatoes$texture, tasty_potatoes$moistness)
boxplot(demo$gdp)

// Select the hot dog with the least calories: lily
lily <- hotdogs[which.min(hotdogs$calories), ]

# PART2

install.packages("readr")
library(readr)

potatoes_fragment <- read_tsv("potatoes.txt", skip = 6, n_max = 5, col_names = properties)
potatoes <- fread("potatoes.csv")

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

// correlação de Pearson - dependencia linear entre duas variáveis e vai de 1 a -1
// 1 é muita dependência, 0 são independetes, -1 sem dependência nenhuma
cor(size$height, size$width)

## cleaning data in R

# PART 1

class(lunch) // get type of data
dim(lunch) // dimension
names(lunch) // get column names

library(dplyr)
glimpse(lunch) // like str

head(lunch, n=15)
tail(lunch, n=15)

hist(lunch$perc_free_red) // histogram
plot(lunch$year, lunch$perc_free_red) // scatter plot

# PART 2

tidyr
gather(wide_df, my_key, my_val, -col)
spread(long_df, my_key, my_val)
separate(treatments, year_mo, c("year", "month"), sep="-")
unit(treatments, year_mo, year, month, sep="-")

# Gather the month columns
census2 <- gather(census, month, amount, -YEAR)

# Arrange rows by YEAR using dplyrs arrange
census2 <- arrange(census2, YEAR)

# PART 3

as.character(2016)
as.numeric(TRUE)
as.integer(99)
as.factor("something")
as.logical(0)

library(lubridate)
ymd("2015-08-25")
ymd("2015 August 25")
mdy("August 25, 2015")
hms("13:33:09")
ymd_hms(2015/08/25 13.33.09)

library(stringr)
str_trim("remove  whitespace")
str_pad("245", width=7, side="left", pad="0")
str_detect(friends, "Alice") // detect presence
str_replace(friends, "Alice", "David") // replace Alice by David
tolower
toupper

df <- data.frame(A = c(1, NA, 8, NA),
				 B = c(3, NA, 88, 23),
				 C = c(2, 45, 3, 1))
is.na(df)
any(is.na(df))				 
sum(is.na(df))				

complete.cases(df)
df[complete.cases(df)]
na.omit(df)

boxplot(x, horizontal = TRUE) // see outliers3
hist(data, breaks = 29)

# PART 4

weather4 <- unite(weather3, date, year, month, day, sep = "-")
weather5 <- select(weather4, date, Events, CloudCover:WindDirDegrees)

ind <- which(weather6$Mean.VisibilityMiles == -1) 

## data manipulation in r with dplyr

# PART 1

library(dplyr)
library(hflights)

hflights <- tbl_df(hflights) // transform in a tibble
glimpse(hflights)
as.data.frame(hflights)

lut <- c("A" = "carrier", "B" = "weather", "C" = "FFA", "D" = "security", "E" = "not cancelled")
hflights$Code <- lut[hflights$CancellationCode]
glimpse(hflights)

# PART 2

select //  returns a subset of the columns
mutate // add columns from existing data
filter //  return a subset of the rows
arrange // reorders the rows according to single or multiple variables,
summarize // reduces each group to a single row by calculating aggregate measures

select(table, columns to maintain)
select(hflights, ActualElapsedTime, AirTime, ArrDelay, DepDelay) // do not modify 
select(df, 1:4, -2)
print(select(hflights, Origin:Cancelled))
select(hflights, Year:DayOfWeek, ArrDelay:Diverted)
 
# PART 3
# PART 4
# PART 5

