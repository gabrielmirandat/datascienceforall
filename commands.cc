# head(sapply(orient_prof_unb_json[["ORIENTACAO_EM_ANDAMENTO_GRADUACAO"]][["2017"]], function (x) unlist(x$"nome_aluno")) %>% sort)

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

# The base layer, cyl.am, is available for you
# Add geom (position = "stack" by default)
cyl.am + 
  geom_bar()

# Fill - show proportion
cyl.am + 
  geom_bar(position = "fill")  

# Dodging - principles of similarity and proximity
cyl.am +
  geom_bar(position = "dodge") 

# Clean up the axes with scale_ functions
val = c("#E41A1C", "#377EB8")
lab = c("Manual", "Automatic")
cyl.am +
  geom_bar(position = "dodge") +
  scale_x_discrete("Cylinders") + 
  scale_y_continuous("Number") +
  scale_fill_manual("Transmission", 
                    values = val,
                    labels = lab)

# 1 - Create jittered plot of mtcars, mpg onto x, 0 onto y
ggplot(mtcars, aes(x = mpg, y = 0)) +
  geom_jitter()

# 2 - Add function to change y axis limits
ggplot(mtcars, aes(x = mpg, y = 0)) +
  geom_jitter() +
  scale_y_continuous(limits=c(-2, 2))

# Basic scatter plot: wt on x-axis and mpg on y-axis; map cyl to col
ggplot(mtcars, 
aes(x = wt, y = mpg, col = cyl)) +
geom_point(size=4)


# Hollow circles - an improvement
ggplot(mtcars, 
aes(x = wt, y = mpg, col = cyl)) +
geom_point(size=4, shape=1)


# Add transparency - very nice
ggplot(mtcars, 
aes(x = wt, y = mpg, col = cyl)) +
geom_point(alpha=0.6, size = 4)

# Scatter plot: carat (x), price (y), clarity (color)
ggplot(diamonds, 
aes(x = carat, y = price, col = clarity)) +
geom_point()


# Adjust for overplotting
ggplot(diamonds, 
aes(x = carat, y = price, col = clarity)) +
geom_point(alpha = 0.5)


# Scatter plot: clarity (x), carat (y), price (color)
ggplot(diamonds, 
aes(x = clarity, y = carat, col = price)) +
geom_point(alpha = 0.5)


# Dot plot with jittering
ggplot(diamonds, 
aes(x = clarity, y = carat, col = price)) +
geom_point(alpha = 0.5, position = "jitter")

# PART 4

# 2 - Set width in geom_jitter()
ggplot(mtcars, aes(x = cyl, y = wt)) +
  geom_jitter(width = 0.1)

# 3 - Set position = position_jitter() in geom_point() ()
ggplot(mtcars, aes(x = cyl, y = wt)) +
  geom_point(position = position_jitter(0.1))

# 1 - Make a univariate histogram
ggplot(mtcars, aes(x=mpg)) +
   geom_histogram()

# 2 - Plot 1, plus set binwidth to 1 in the geom layer
ggplot(mtcars, aes(x=mpg)) +
   geom_histogram(binwidth = 1)


# 3 - Plot 2, plus MAP ..density.. to the y aesthetic (i.e. in a second aes() function)
ggplot(mtcars, aes(x=mpg)) +
   geom_histogram(binwidth = 1, aes(y=..density..))



# 4 - plot 3, plus SET the fill attribute to "#377EB8"
ggplot(mtcars, aes(x=mpg)) +
   geom_histogram(binwidth = 1,fill="#377EB8", aes(y=..density..))


# Draw a bar plot of cyl, filled according to am
ggplot(mtcars, aes(x = cyl, fill = am)) +
  geom_bar()

# Change the position argument to stack
ggplot(mtcars, aes(x = cyl, fill = am)) +
  geom_bar(position="stack")


# Change the position argument to fill
ggplot(mtcars, aes(x = cyl, fill = am)) +
  geom_bar(position="fill")


# Change the position argument to dodge
ggplot(mtcars, aes(x = cyl, fill = am)) +
  geom_bar(position="dodge")

ggplot(mtcars, aes(mpg,col=cyl)) +
  geom_freqpoly(binwidth=1)  

# Example of how to use a brewed color palette
ggplot(mtcars, aes(x = cyl, fill = am)) +
  geom_bar() +
  scale_fill_brewer(palette = "Set1")

# Use str() on Vocab to check out the structure
str(Vocab)

# Plot education on x and vocabulary on fill
# Use the default brewed color palette
ggplot(Vocab, aes(x=education, fill=vocabulary)) +
   geom_bar(position = "fill") + 
   scale_fill_brewer()

# Definition of a set of blue colors
blues <- brewer.pal(9, "Blues") # from the RColorBrewer package

# 1 - Make a color range using colorRampPalette() and the set of blues
blue_range <- colorRampPalette(blues)

# 2 - Use blue_range to adjust the color of the bars, use scale_fill_manual()
ggplot(Vocab, aes(x = education, fill = vocabulary)) +
  geom_bar(position = "fill") +
  scale_fill_manual(values = blue_range(11))

# 6 - Plot 5, plus change mapping: cyl onto fill
ggplot(mtcars, aes(mpg, fill = cyl)) +
  geom_histogram(binwidth = 1, position = "identity", alpha=0.4)

SCATTER = points, jitter, abline
BAR = histogram, bar, errorbar
LINE = line     

# Adjust plot to represent the fraction of total population that is unemployed
ggplot(economics, aes(x = date, y = unemploy/pop)) +
geom_line()

# Expand the following command with geom_rect() to draw the recess periods
ggplot(economics, aes(x = date, y = unemploy/pop)) +
  geom_rect(data = recess,
         aes(xmin = begin, xmax = end, ymin = -Inf, ymax = +Inf),
         inherit.aes = FALSE, fill = "red", alpha = 0.2) +
  geom_line()

ggplot(fish.tidy, aes(x = Year, y = Capture, col = Species)) +
geom_line()

# PART 5

qplot(wt, mpg, data = mtcars)
qplot(factor(cyl), factor(vs), data = mtcars, geom="jitter")

# 2 - qplot with geom "dotplot", binaxis = "y" and stackdir = "center"
qplot(
  cyl, wt,
  data = mtcars,
  fill = am,
  geom = "dotplot",
  binaxis = "y",
  stackdir = "center"
)

# 4 - Take plot 3, add geom_smooth()
ggplot(ChickWeight, aes(x = Time, y = weight,color=Diet)) +
  geom_line(aes(group = Chick, alpha=0.3)) + 
  geom_smooth(lwd=2, se=FALSE)

# 5 - Plot 3, but use the position object from instruction 4
ggplot(titanic, aes(x = Pclass, y=Age, col = Sex)) +
  geom_point(size = 3, alpha = 0.5 ,position = posn.jd)+
  facet_grid(. ~ Survived)


## Joining Data in R with dplyr

# PART 1

Mutating joins
Filtering joins and set operations
Assembling data
Advanced joining
Case study

merge()
left_join(names, plays, by="name")
right_join(names, plays, by="name")

bands2 <- left_join(bands, artists, by = c('first','last'))
bands3 <- right_join(artists, bands, by = c("first", "last"))

inner_join(, y, by="")
full_join(x,y,by="")

inner_join(songs, albums, by = "album")
full_join(artists, bands, by = c("first","last"))

bands %>% 
  left_join(artists, by = c("first", "last")) %>%
  filter(instrument == "Guitar") %>%
  select(first, last, band)

goal2 <- artists %>%
full_join(bands, by = c("first","last")) %>%
inner_join(songs, by = c("first","last"))

collection <- artists %>%
  full_join(bands, by = c("first","last")) %>%
  full_join(songs, by = c("first","last")) %>%
  full_join(albums, by = c("album", "band"))
  
collection

# PART 2

// filtra so os que batem
semi_join (x,y,by="")

// filtra so os que não batem
anti_join (x,y,by="")

// union, intersection, setdiff
union(f,s)
intersection(f,s)
setdiff(f,s)

// check same
setequal(f,s)

# View the output of semi_join()
artists %>% 
  semi_join(songs, by = c("first", "last"))

# Create the same result
artists %>% 
  right_join(songs, by = c("first", "last")) %>% 
  filter(!is.na(instrument)) %>% 
  select(first, last, instrument)

albums %>% 
  # Collect the albums made by a band
  semi_join(bands, by="band") %>% 
  # Count the albums made by a band
  nrow()

artists %>% 
  anti_join(bands, by=c("first", "last"))

songs %>% 
  # Find the rows of songs that match a row in labels
  semi_join(labels, by="album") %>% 
  # Number of matches between labels and songs
  nrow()

# Create the new dataset using a set operation
live_songs %>% 
  setdiff(greatest_songs)

# Return the songs that only exist in one dataset
all_songs <- union(live_songs, greatest_songs)
both_songs <- intersect(live_songs, greatest_songs)
one_songs <- setdiff(all_songs, both_songs)
one_songs

# Return songs in definitive that are not in complete
definitive %>% 
  anti_join(complete, by = c("song", "album"))

# Return songs in complete that are not in definitive
complete %>% 
  anti_join(definitive, by = c("song", "album"))
  
# PART 3

// merge rows
// base R
rbind()
cbind()
// dplyr
bind_rows()
bind_cols()
bind_rows(Beatles=band1, Stones=band2, .id="band")

jimi %>% 
  # Bind jimi into a single data frame
  bind_rows(.id = "album") %>% 
  # Make a complete data frame
  left_join(discography, by = c("album"))

// criar dataframe
// base R
data.frame()
as.data.frame()
// dplyr
data_frame()
as_data_frame()

data_frame(
  year = hank_year,
  song = hank_song,
  peak = hank_peak
  ) %>% 
  # Extract songs where peak equals 1
  filter(peak == 1)

as_data_frame(hank) %>% 
  # Extract songs where peak equals 1
  filter(peak == 1)

# Now we can join the datasets correctly
seventies %>% 
  # Coerce seventies$year into a useful numeric
  mutate(year = as.numeric(as.character(year))) %>% 
  # Bind the updated version of seventies to sixties
  bind_rows(sixties) %>% 
  arrange(year)

# PART4
library(tibble)

stage_songs %>% 
  # Add row names as a column named song
  rownames_to_column("song") %>% 
  # Left join stage_writers to stage_songs
  left_join(stage_writers, by = "song")

# Remove NAs from key before joining
two_songs %>% 
  filter(!is.na(movie)) %>% 
  inner_join(singers, by = "movie")

movie_years %>% 
  # Left join movie_studios to movie_years
  left_join(movie_studios, by = "movie") %>% 
  # Rename the columns: artist and studio
  rename(artist = name.x, studio = name.y)

elvis_movies %>% 
  # Left join elvis_songs to elvis_movies by this column
  left_join(elvis_songs, by = c("name" = "movie")) %>% 
  # Rename columns
  rename(movie = name, song = name.y)

movie_years %>% 
  # Left join movie_directors to movie_years
  left_join(movie_directors, by = c("movie" = "name")) %>% 
  # Arrange the columns using select()
  select(year, movie, artist = name, director, studio)

library(purrr)
reduce(tables, left_join, by = "name")  

# Load the purrr library
library(purrr)

# Place supergroups, more_bands, and more_artists into a list
list(supergroups, more_bands, more_artists) %>% 
  # Use reduce to join together the contents of the list
  reduce(left_join, by = c("first" = "first","last" = "last"))

list(more_artists, more_bands, supergroups) %>% 
  # Return rows of more_artists in all three datasets
  reduce(semi_join, by = c("first","last"))

# Alter the code to perform the join with a dplyr function
merge(bands, artists, by = c("first", "last"), all.x = TRUE) %>%
  arrange(band) É O MESMO DE 
bands %>% left_join(artists, by = c("first", "last"))

library(Lahman)

# Examine lahmanNames
lahmanNames

# Find variables in common
reduce(lahmanNames, intersect)

lahmanNames %>%  
  # Bind the data frames in lahmanNames
  bind_rows(.id = 'dataframe') %>%
  # Group the result by var
  group_by(var) %>%
  # Tally the number of appearances
  tally() %>%
  # Filter the data
  filter(n > 1) %>% 
  # Arrange the results
  arrange(desc(n))

lahmanNames %>% 
  # Bind the data frames
  bind_rows(.id = 'dataframe') %>%
  # Filter the results
  filter(var == 'playerID') %>% 
  # Extract the dataframe variable
  `$`(dataframe)

players <- Master %>% 
  # Return one row for each distinct player
  distinct(playerID, nameFirst, nameLast)
  
nrow(players)

players %>% 
  # Find all players who do not appear in Salaries
  anti_join(Salaries, by = 'playerID') %>%
  # Count them
  count()
    
players %>% 
  anti_join(Salaries, by = "playerID") %>% 
  # How many unsalaried players appear in Appearances?
  semi_join(Appearances, by = "playerID") %>% 
  count()

players %>% 
  # Find all players who do not appear in Salaries
  anti_join(Salaries, by = "playerID") %>% 
  # Join them to Appearances
  left_join(Appearances, by = "playerID") %>% 
  # Calculate total_games for each player
  group_by(playerID) %>%
  summarise(total_games = sum(G_all, na.rm = T)) %>%
  # Arrange in descending order by total_games
  arrange(desc(total_games))

players %>%
  # Find unsalaried players
  anti_join(Salaries, by = "playerID") %>% 
  # Join Batting to the unsalaried players
  left_join(Batting, by = "playerID") %>% 
  # Group by player
  group_by(playerID) %>% 
  # Sum at-bats for each player
  summarize(total_at_bat = sum(AB, na.rm = T)) %>% 
  # Arrange in descending order
  arrange(desc(total_at_bat))

# Find the distinct players that appear in HallOfFame
nominated <- HallOfFame %>% 
  distinct(playerID)

nominated %>% 
  # Count the number of players in nominated
  count()

nominated_full <- nominated %>% 
  # Join to Master
  left_join(Master, by = "playerID") %>% 
  # Return playerID, nameFirst, nameLast
  select(playerID, nameFirst, nameLast)

head(nominated_full)

# Find distinct players in HallOfFame with inducted == "Y"
inducted <- HallOfFame %>% 
  filter(inducted == "Y") %>%
  distinct(playerID)

# Note if you wanted to keep all of the columns you can use keep_all in the distinct function
HallOfFame %>%
  distinct(playerID, .keep_all = TRUE) %>%
  filter(inducted == "Y") %>% 
  head()
  
inducted %>% 
  # Count the number of players in inducted
  count()
  
inducted_full <- inducted %>% 
  # Join to Master
  left_join(Master, by = "playerID") %>% 
  # Return playerID, nameFirst, nameLast
  select(playerID, nameFirst, nameLast)

head(inducted_full)

# Tally the number of awards in AwardsPlayers by playerID
nAwards <- AwardsPlayers %>% 
  group_by(playerID) %>% 
  tally()

head(nAwards)

nAwards %>% 
  # Filter to just the players in inducted 
  semi_join(inducted, by = "playerID") %>% 
  # Calculate the mean number of awards per player
  summarize(avg_n = mean(n, na.rm = T))
  
nAwards %>% 
  # Filter to just the players in nominated 
  semi_join(nominated, by = "playerID") %>% 
  # Filter to players NOT in inducted 
  anti_join(inducted, by = "playerID") %>%
  # Calculate the mean number of awards per player
  summarize(avg_n = mean(n, na.rm = T))

# Find the players who are in nominated, but not inducted
notInducted <- nominated %>% 
  setdiff(inducted, by = "playerID")

Salaries %>% 
  # Find the players who are in notInducted
  semi_join(notInducted) %>%
  # Calculate the max salary by player
  group_by(playerID) %>% 
  summarize(max_salary = max(salary)) %>% 
  # Calculate the average of the max salaries
  summarize(avg_salary = mean(max_salary))
  
  # Repeat for players who were inducted
Salaries %>% 
  semi_join(inducted) %>%
  # Calculate the max salary by player
  group_by(playerID) %>% 
  summarize(max_salary = max(salary)) %>% 
  # Calculate the average of the max salaries
  summarize(avg_salary = mean(max_salary))
  
Appearances %>% 
  # Filter Appearances against nominated
  semi_join(nominated, by = "playerID") %>%
  # Find last year played by player
  group_by(playerID) %>% 
  summarize(last_year = max(yearID)) %>%
  # Join to full HallOfFame
  left_join(HallOfFame, by = "playerID") %>% 
  # Filter for unusual observations
  filter(yearID <= last_year)

## exploratory-data-analysis-in-r-case-study

# PART 1

# Add a country column within the mutate: votes_processed
votes_processed <- votes %>%
  filter(vote <= 3) %>%
  mutate(
    year = session + 1945,
    country = countrycode(ccode, "cown", "country.name"),
    country = recode(country, 
                     'United States of America' =  'United States',
                     'United Kingdom of Great Britain and Northern Ireland' = 'United Kingdom')
    )

votes_processed %>%
  summarise(
    total = n(),
    percent_yes = mean(vote == 1)
    )

votes_processed %>%
  group_by(year) %>%
  summarize(total = n(),
            percent_yes = mean(vote == 1))

by_country <- votes_processed %>%
  group_by(country) %>%
  summarize(total = n(),
            percent_yes = mean(vote == 1))
by_country

by_country <- votes_processed %>%
  group_by(country) %>%
  summarize(total = n(),
            percent_yes = mean(vote == 1))

# Print the by_country dataset
by_country

# Sort in ascending order of percent_yes
by_country %>%
  arrange(percent_yes)

# Now sort in descending order
by_country %>%
  arrange(desc(percent_yes))

# Change to scatter plot and add smoothing curve
ggplot(by_year, aes(year, percent_yes)) +
  geom_point() +
  geom_smooth()

# Group by year and country: by_year_country
by_year_country <- votes_processed %>%
  group_by(year, country) %>%
  summarize(total = n(),
            percent_yes = mean(vote == 1))

# Vector of four countries to examine
countries <- c("United States", "United Kingdom",
               "France", "India")

# Filter by_year_country: filtered_4_countries
filtered_4_countries <- by_year_country %>%
  filter(country %in% countries)

# Line plot of % yes in four countries
ggplot(filtered_4_countries, aes(x = year, y = percent_yes, color = country)) +
  geom_line()

# Vector of six countries to examine
countries <- c("United States", "United Kingdom",
               "France", "Japan", "Brazil", "India")

# Filtered by_year_country: filtered_6_countries
filtered_6_countries <- by_year_country %>%
  filter(country %in% countries)

# Line plot of % yes over time faceted by country
ggplot(filtered_6_countries, aes(x = year, y = percent_yes)) +
  geom_line() + 
  facet_wrap(~ country)

# Load the broom package
library(broom)

# Call the tidy() function on the US_fit object
tidy(US_fit)

# Linear regression of percent_yes by year for US
US_by_year <- by_year_country %>%
  filter(country == "United States")
US_fit <- lm(percent_yes ~ year, US_by_year)

# Fit model for the United Kingdom
UK_by_year <- by_year_country %>%
  filter(country == "United Kingdom")
UK_fit <- lm(percent_yes ~ year, UK_by_year)

# Create US_tidied and UK_tidied
US_tidied <- tidy(US_fit)
UK_tidied <- tidy(UK_fit)

# Combine the two tidied models
bind_rows(US_tidied, UK_tidied)

# Load the tidyr package
library(tidyr)

# Nest all columns besides country
by_year_country %>%
  nest(-country)

# All countries are nested besides country
nested <- by_year_country %>%
  nest(-country)

nested$data[[1]]

nested$data[[1]]$percent_yes

# Print the nested data for Brazil
nested$data[nested$country == 'Brazil']

# All countries are nested besides country
nested <- by_year_country %>%
  nest(-country)

# Unnest the data column to return it to its original form
nested %>%
  unnest()

# Load tidyr and purrr
library(tidyr)
library(purrr)


# Perform a linear regression on each item in the data column
by_year_country %>%
  group_by(country) %>%
  nest() %>%
  mutate(
    model = map(data, ~ lm(percent_yes ~ year, data = .))
    )

# Filter for only the slope terms
country_coefficients %>%
  filter(term == 'year')

# Filter for only the slope terms
slope_terms <- country_coefficients %>%
  filter(term == "year")

# Add p.adjusted column, then filter
slope_terms %>%
  mutate(p.adjusted = p.adjust(p.value)) %>% 
  data.frame() %>% head()

# Filter by adjusted p-values
filtered_countries <- country_coefficients %>%
  filter(term == "year") %>%
  mutate(p.adjusted = p.adjust(p.value)) %>%
  filter(p.adjusted < .05)

# Sort for the countries increasing most quickly
filtered_countries %>%
  arrange(desc(estimate))

# Sort for the countries decreasing most quickly
filtered_countries %>%
  arrange(estimate)

# Gather the six me/nu/di/hr/co/ec columns
votes_joined %>%
  gather(topic, has_topic, one_of("me","nu","di","hr","co","ec"))

# Perform gather again, then filter
votes_gathered <- votes_joined %>%
  gather(topic, has_topic, one_of("me","nu","di","hr","co","ec")) %>%
  filter(has_topic == 1)

# Replace the two-letter codes in topic: votes_tidied
votes_tidied <- votes_gathered %>%
  mutate(topic = recode(topic,
                        me = "Palestinian conflict",
                        nu = "Nuclear weapons and nuclear material",
                        di = "Arms control and disarmament",
                        hr = "Human rights",
                        co = "Colonialism",
                        ec = "Economic development"))

# Fit model on the by_country_year_topic dataset
country_topic_coefficients <- by_country_year_topic %>%
  nest(-country, -topic) %>%
  mutate(
    model = map(data, ~ lm(percent_yes ~ year, data = .)),
    tidied = map(model, tidy)
    ) %>%
  unnest(tidied)

  ## data-visualization-with-ggplot2-2

  - statistics, coordinates, facets, themes

# The previous plot, without CI ribbon:
ggplot(mtcars, aes(x = wt, y = mpg)) +
  geom_point() + 
  geom_smooth(method = "lm", se = F)


# The previous plot, without points:
ggplot(mtcars, aes(x = wt, y = mpg)) + 
  geom_smooth(method = "lm", se = F)                                         

## In this ggplot command our smooth is calculated for each subgroup 
## because there is an invisible aesthetic, group which inherits from col.
ggplot(mtcars, aes(x = wt, y = mpg, col = factor(cyl))) +
  geom_point() +
  stat_smooth(method = "lm", se = F)

# Setting the group to 1 in the aes() will override the groups
ggplot(mtcars, aes(x = wt, y = mpg, col = factor(cyl))) +
  geom_point() +
  stat_smooth(method = "lm", se = F) + 
  stat_smooth(aes(group = 1), method = "lm", se = F)

# Plot 1: Jittered scatter plot, add a linear model (lm) smooth:
ggplot(Vocab, aes(x = education, y = vocabulary)) +
  geom_jitter(alpha = 0.2) +
  stat_smooth(method = "lm", se = F)
  
# Plot 2: Only lm, colored by year
ggplot(Vocab, aes(x = education, y = vocabulary, col = factor(year))) +
  stat_smooth(method = "lm", se = F)
  
# Plot 3: Set a color brewer palette
## This will give a warning and not work becuse the default palette
## "Blues" only has 9 colors, but we have 16 years
ggplot(Vocab, 
       aes(x = education, y = vocabulary, col = factor(year))) +
  stat_smooth(method = "lm", se = F) + 
  scale_color_brewer()
  
# Plot 4: Add the group, specify alpha and size
ggplot(Vocab, 
       aes(x = education, y = vocabulary, col = year, group = factor(year))) +
  stat_smooth( method = "lm", 
              se = F, 
              alpha = 0.6, 
              size = 2) +
  scale_color_gradientn(colors = brewer.pal(9,"YlOrRd"))
  
# Use stat_quantile instead of stat_smooth
ggplot(Vocab, aes(x = education, y = vocabulary, col = year, group = factor(year))) +
  stat_quantile(alpha = 0.6, size=2) +
  scale_color_gradientn(colors = brewer.pal(9,"YlOrRd"))

# Set quantile to 0.5
ggplot(Vocab, aes(x = education, y = vocabulary, col = year, group = factor(year))) +
  stat_quantile(alpha = 0.6, quantiles=0.5, size=2) +
  scale_color_gradientn(colors = brewer.pal(9,"YlOrRd"))

# The base ggplot command, you dont have to change this
wt.cyl.am <- ggplot(mtcars, aes(x = cyl,y = wt, col = am, fill = am, group = am))

# Add three stat_summary calls to wt.cyl.am
wt.cyl.am + 
  stat_summary(
    geom = "linerange", 
    fun.data = med_IQR, 
    position = posn.d, 
    size = 3) +
  stat_summary(
    geom = "linerange", 
    fun.data = gg_range, 
    position = posn.d, 
    size = 3, 
    alpha = 0.4) +
  stat_summary(
    geom = "point", 
    fun.y = median, 
    position = posn.d, 
    size = 3, 
    col = "black", 
    shape = "X")

# Basic ggplot() command, coded for you
p <- ggplot(mtcars, aes(x = wt, y = hp, col = am)) + geom_point() + geom_smooth()

# Add scale_x_continuous
## The wrong way to zoom in. You lose data and the stats will dissapear or be incorrect.
p + scale_x_continuous(limits = c(3,6), expand = c(0,0))

# The proper way to zoom in:
p + coord_cartesian(xlim = c(3,6))

# Create a stacked bar plot: wide.bar
wide.bar <- ggplot(mtcars, aes(x = 1, fill = cyl)) +
              geom_bar()

# Convert wide.bar to pie chart
wide.bar +
  coord_polar(theta = "y")

# Create stacked bar plot: thin.bar
thin.bar <- ggplot(mtcars, aes(x = 1, fill = cyl)) +
              geom_bar(width = .1) +
              scale_x_continuous(limits = c(0.5,1.5))

# Convert thin.bar to "ring" type pie chart
thin.bar +
  coord_polar(theta = "y")

# Basic scatter plot:
p <- ggplot(mtcars, aes(x = wt, y = mpg)) +
  geom_point()

# Separate rows according to transmission type, am
p + facet_grid(am ~ .)

# Separate columns according to cylinders, cyl
p + facet_grid(. ~ cyl)

# Separate by both columns and rows 
p + facet_grid(am ~ cyl)

head(mamsleep)

str(mamsleep)

# Basic scatter plot
ggplot(mamsleep, aes(time, name, col = sleep)) +
  geom_point()
  
# Execute to display plot
p

# Facet rows accoding to vore
ggplot(mamsleep, aes(time, name, col = sleep)) +
  geom_point() + 
  facet_grid(vore ~ .)

# Specify scale and space arguments to free up rows
ggplot(mamsleep, aes(time, name, col = sleep)) +
  geom_point() + 
  facet_grid(vore ~ ., scale = "free_y", space = "free_y")

# Starting point
z

# Plot 1: Change the plot background fill to myPink
z + 
  theme(plot.background = element_rect(fill = myPink))

# Plot 2: Adjust the border to be a black line of size 3
z + 
  theme(plot.background = element_rect(fill = myPink, color = "black", size = 3)) # expanded from plot 1

# Theme to remove all rectangles
no_panels <- theme(rect = element_blank())

# Plot 3: Combine custom themes
z +
  no_panels +
  theme(plot.background = element_rect(fill = myPink, color = "black", size = 3))  # from plot 2

# Extend z with theme() function and three arguments
z <- z + theme(
  panel.grid = element_blank(),
  axis.line = element_line(color = "red"),
  axis.ticks = element_line(color = "red")
  )
z

