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
gather(wide_df, my_key, my_val, -col) // pega todas as colunas sem - e separa, sempre gerando uma coluna chamada Value
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

"
select //  returns a subset of the columns
mutate // add columns from existing data, data already contained but not displayed
filter //  return a subset of the rows
arrange // reorders the rows according to single or multiple variables, major to minor
summarize // reduces each group to a single row by calculating aggregate measures
"

select(table, columns to maintain)
select(hflights, ActualElapsedTime, AirTime, ArrDelay, DepDelay) // do not modify 
select(df, 1:4, -2)
select(hflights, Origin:Cancelled)
select(hflights, Year:DayOfWeek, ArrDelay:Diverted)
dplyr // helper select
	starts_with("X"), ends_with("X"), contains("X"), matches("X"), num_range("x", 1:5), one_of(x)
select(hflights, ends_with("Delay"))
select(hflights, UniqueCarrier, ends_with("Num"), contains("Cancel"))
ex2d <- select(hflights, Year:ArrTime, -3)

mutate(h1, loss = ArrDelay - DepDelay)
mutate(my_df, x = a + b, y = x + c)

# PART 3

filter(hflights, Cancelled == 1)

x < y, TRUE if x is less than y
x <= y, TRUE if x is less than or equal to y
x == y, TRUE if x equals y
x != y, TRUE if x does not equal y
x >= y, TRUE if x is greater than or equal to y
x > y, TRUE if x is greater than y
x %in% c(a, b, c), TRUE if x is in the vector c(a, b, c)

glimpse(hflights)
filter(hflights, Distance >= 3000)
filter(hflights, UniqueCarrier %in% c("JetBlue","Southwest","Delta"))
filter(hflights, (TaxiIn + TaxiOut) > AirTime)
filter(hflights, DepTime < 500 |  ArrTime > 2200)
filter(hflights, DepDelay > 0 & ArrDelay < 0)
filter(hflights, Cancelled == 1 & DepDelay > 0)
temp1 <- filter(hflights, !is.na(ArrDelay))
temp2 <- filter(hflights, !is.na(TaxiIn) & !is.na(TaxiOut))

c1 <- filter(hflights, Dest == "JFK")
c2 <- mutate(c1, Date = paste(Year,Month,DayofMonth, sep="-"))
select(c2, Date, DepTime, ArrTime, TailNum)

arrange(a1, DepDelay, ArrDelay)

# PART 4

summarize(df, sum = sum(A), avg = mean(B), var = var(B))
summarise(temp2, max_taxi_diff = max(abs(TaxiIn - TaxiOut)))

summarise(aa,
    n_flights = n(),
    n_canc = sum(Cancelled),
    p_canc = n_canc/n_flights * 100,
    avg_delay = mean(ArrDelay, na.rm=TRUE))

// min(x) - minimum value of vector x.
// max(x) - maximum value of vector x.
// mean(x) - mean value of vector x.
// median(x) - median value of vector x.
// quantile(x, p) - pth quantile of vector x.
// sd(x) - standard deviation of vector x.
// var(x) - variance of vector x.
// IQR(x) - Inter Quartile Range (IQR) of vector x.
// diff(range(x)) - total range of vector x.

library(dplyr)
// first(x) - The first element of vector x.
// last(x) - The last element of vector x.
// nth(x, n) - The nth element of vector x.
// n() - The number of rows in the data.frame or group of observations that summarise() describes.
// n_distinct(x) - The number of unique values in vector x

PIPE
library(magritr)
%>%

aa %>%
	select(X, Y, Z) %>%
	filter(X > Y) %>%
	mutate(Q = X + Y + Z) %>%
	summarise(all = sum(Q))

hflights %>% mutate(diff = TaxiOut - TaxiIn) %>%
            filter(!is.na(diff)) %>%
            summarise(avg = mean(diff))	

# Chain together mutate(), filter() and summarise()
d <- hflights %>%
  select(Dest, UniqueCarrier, Distance, ActualElapsedTime) %>%
  mutate(
    RealTime = ActualElapsedTime + 100,
    mph = Distance/RealTime*60
    )
    
d %>%
  filter(
    !is.na(mph),
    mph < 70
    ) %>%
  summarize(
    n_less = n(),
    n_dest = n_distinct(Dest),
    min_dist = min(Distance),
    max_dist = max(Distance)
    )

  hflights %>%
  filter(
    !is.na(ArrTime),
    !is.na(DepTime),
    ArrTime < DepTime
    ) %>%
  summarise(n = n())

# PART 5

"
group_by(df, Group) // make groups in the dataset
"

hflights %>%
  group_by(UniqueCarrier) %>%
  summarise(p_canc = sum(Cancelled)/n() * 100,
            avg_delay = mean(ArrDelay, na.rm=TRUE)) %>%
  arrange(avg_delay, p_canc)

 rank() takes a group of values and calculates the rank of each value within the group  

## Data Visualization with ggplot2 (Part 1)

# PART 1

'Exploratory analysis' is what you do to get familiar with the data. You may start out with a hypothesis or question.
					   youre not concerned with beautiful at this point
'Explanatory analysis' is what happens when you have something specific you want to show an audience - probably about those 1 or 2 precious gemstones

library(ggplot)
ggplot(mammals, aes(x = body, y = brain)) + geom_point()

ggplot(mammals, aes(x = body, y = brain)) + geom_point(alpha = 0.6) + stat_smooth(method = "lm", col = "red", se = FALSE)

ggplot(mammals, aes(x = body, y = brain)) + geom_point(alpha = 0.6) + coord_fixed() + 
	scale_x_log10() + scale_y_log10() + stat_smooth(method = "lm", col = "#C42126", se = FALSE, size = 1)

ggplot(mtcars, aes(x = factor(cyl), y = mpg)) + geom_point() // because cyl (n of cylinders) is categorical

ggplot(iris, aes(x = Sepal.Length, y = Sepal.Width)) + 
	geom_jitter(alpha = 0.6) +
	facet_grid(. ~ Species) + 
	stat_smooth(method = "lm", se = F, col = "red")
	scale_y_continuos("Sepal Width (cm)",
						limits = c(2,5),
						expand = c(0,0)) + 
	scale_x_continuos("Sepal Length (cm)",
						limits = c(4,8),
						expand = c(0,0)) + 
	coord_equal()

# 1 - The plot you created in the previous exercise
ggplot(diamonds, aes(x = carat, y = price)) +
  geom_point() +
  geom_smooth()

# 2 - Copy the above command but show only the smooth line
ggplot(diamonds, aes(x = carat, y = price)) +
  geom_smooth()

# 3 - Copy the above command and assign the correct value to col in aes()
ggplot(diamonds, aes(x = carat, y = price, color = clarity)) +
  geom_smooth()

# 4 - Keep the color settings from previous command. Plot only the points with argument alpha.
ggplot(diamonds, aes(x = carat, y = price, color = clarity)) + 
  geom_point(alpha = 0.4)

dia_plot + geom_point(aes(color = clarity))

dia_plot + geom_smooth(aes(col = clarity), se = F)  

# PART 2

mtcars$cyl <- as.factor(mtcars$cyl)
plot(mtcars$wt, mtcars$mpg, col = mtcars$cyl)
abline(carModel, lty = 2)
plot(mtcars$wt, mtcars$mpg, col = mtcars$cyl)
lapply(mtcars$cyl, function(x) {
  abline(lm(mpg ~ wt, mtcars, subset = (cyl == x)), col = x)
  })
legend(x = 5, y = 33, legend = levels(mtcars$cyl),
       col = 1:3, pch = 1, bty = "n")

# Plot 3: include a lm for the entire dataset in its whole
ggplot(mtcars, aes(x = wt, y = mpg, col = cyl)) +
  geom_point() + # Copy from Plot 1
  geom_smooth(method = 'lm', se = F) +  # Fill in using instructions Plot 2
  geom_smooth(aes(group = 1), method = 'lm', se = F, linetype = 2)   # Fill in using instructions Plot

iris.tidy <- iris %>%
  gather(key, Value, -Species) %>%
  separate(key, c("Part", "Measure"), "\\.")  

# PART 3

mpg -- Miles/(US) gallon
cyl -- Number of cylinders
disp -- Displacement (cu.in.)
hp -- Gross horsepower
drat -- Rear axle ratio
wt -- Weight (lb/1000)
qsec -- 1/4 mile time
vs -- V/S engine.
am -- Transmission (0 = automatic, 1 = manual)
gear -- Number of forward gears
carb -- Number of carburetors

Aesthetics
x, y, colour, fill, size, alpha, linetype, labels, shape

# 1 - Map mpg to x and cyl to y
ggplot(mtcars, aes(x = mpg, y = cyl)) +
  geom_point()
  
# 2 - Reverse: Map cyl to x and mpg to y
ggplot(mtcars, aes(y = mpg, x = cyl)) +
  geom_point()

# 3 - Map wt to x, mpg to y and cyl to col
ggplot(mtcars, aes(x = wt, y = mpg, col = cyl)) +
  geom_point()

# 4 - Change shape and size of the points in the above plot
ggplot(mtcars, aes(x = wt, y = mpg, col = cyl)) +
  geom_point(shape = 1, size = 4)

# am and cyl are factors, wt is numeric
class(mtcars$am)
class(mtcars$cyl)
class(mtcars$wt)

# From the previous exercise
ggplot(mtcars, aes(x = wt, y = mpg, col = cyl)) +
  geom_point(shape = 1, size = 4)

# 1 - Map cyl to fill
ggplot(mtcars, aes(x = wt, y = mpg, fill = cyl)) +
  geom_point(shape = 1, size = 4)


# 2 - Change shape and alpha of the points in the above plot
ggplot(mtcars, aes(x = wt, y = mpg, fill = cyl)) +
  geom_point(shape = 21, alpha= 0.6, size = 4)


# 3 - Map am to col in the above plot
ggplot(mtcars, aes(x = wt, y = mpg, fill = cyl, col = am)) +
  geom_point(shape = 21, alpha= 0.6, size = 4)

# Map cyl to size
ggplot(mtcars, aes(x = wt, y = mpg, size = cyl)) +
  geom_point()


# Map cyl to alpha
ggplot(mtcars, aes(x = wt, y = mpg, alpha = cyl)) +
  geom_point()


# Map cyl to shape 
ggplot(mtcars, aes(x = wt, y = mpg, shape = cyl)) +
  geom_point()


# Map cyl to label
ggplot(mtcars, aes(x = wt, y = mpg, label = cyl)) +
  geom_text()

# Define a hexadecimal color
my_color <- "#4ABEFF"

# 1 - First scatter plot, with col aesthetic:
ggplot(mtcars, aes(x = wt, y = mpg, col = cyl)) +
  geom_point()


# 2 - Plot 1, but set col attributes in geom layer:
# 1 - First scatter plot, with col aesthetic:
ggplot(mtcars, aes(x = wt, y = mpg, col = cyl)) +
  geom_point(col = my_color)


# 3 - Plot 2, with fill instead of col aesthetic, plut shape and size attributes in geom layer.
ggplot(mtcars, aes(x = wt, y = mpg, fill = cyl)) +
  geom_point(col = my_color, size = 10, shape = 23)


# Add mapping: (hp/wt) onto size
ggplot(mtcars, aes(x = mpg, y = qsec, col = factor(cyl), shape = factor(am), size = (hp/wt))) +
  geom_point()

  


# PART 4
# PART 5

linkedin