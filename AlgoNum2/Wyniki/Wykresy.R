library(ggplot2)

data <- read.csv("C:\\Users\\Szymon\\OneDrive\\Pulpit\\2rok4sem\\AlgorytmyNumeryczne\\Algorytmy-Numeryczne\\AlgoNum2\\Wyniki\\errors.csv")
data 
ggplot(data, aes(x=N, y=Logs)) +
  geom_line(aes(y=log(GTD)), color='red') +
  geom_line(aes(y=log(PGD)), color='green')

timeGTD <- read.csv("C:\\Users\\Szymon\\OneDrive\\Pulpit\\2rok4sem\\AlgorytmyNumeryczne\\Algorytmy-Numeryczne\\AlgoNum2\\Wyniki\\Czasy\\GTD.csv")
timeGTF <- read.csv("C:\\Users\\Szymon\\OneDrive\\Pulpit\\2rok4sem\\AlgorytmyNumeryczne\\Algorytmy-Numeryczne\\AlgoNum2\\Wyniki\\Czasy\\GTF.csv")
timePGD <- read.csv("C:\\Users\\Szymon\\OneDrive\\Pulpit\\2rok4sem\\AlgorytmyNumeryczne\\Algorytmy-Numeryczne\\AlgoNum2\\Wyniki\\Czasy\\PGD.csv")
timePGF <- read.csv("C:\\Users\\Szymon\\OneDrive\\Pulpit\\2rok4sem\\AlgorytmyNumeryczne\\Algorytmy-Numeryczne\\AlgoNum2\\Wyniki\\Czasy\\PGF.csv")

timeGTD <- timeGTD$moj-timeGTD$impl
timeGTF <- timeGTF$moj-timeGTF$impl
timePGD <- timePGD$moj-timePGD$impl
timePGF <- timePGF$moj-timePGF$impl

time = data.frame(timeGTD, timeGTF, timePGD, timePGF)
time$N <- data$N
time
ggplot(time, aes(x=N, y=Ró¿nica)) +
  geom_line(aes(y=timeGTD), color='red') +
  geom_line(aes(y=timeGTF), color='blue') +
  geom_line(aes(y=timePGD), color='green') +
  geom_line(aes(y=timePGF), color='black')
