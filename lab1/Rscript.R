data <-read.csv('C:\\Users\\48531\\OneDrive\\Pulpit\\Numeryczne\\Algorytmy-Numeryczne\\lab1\\wyniki.csv')

x <- data$arg
mydiff <- function(dobre, zle){
  return((abs(dobre - zle))/dobre)
}
data$errZad1 <- mydiff(data$dobre, data$zad1)
data$errZad2 <- mydiff(data$dobre, data$zad2)
data$errZad3 <- mydiff(data$dobre, data$zad3)
data$errZad4 <- mydiff(data$dobre, data$zad4)
plot(x, data$errZad1, type = 'h')
plot(x, data$errZad2, type = 'h')
plot(x, data$errZad3, type = 'h')
plot(x, data$errZad4, type = 'h')
summary(data$errZad1)
summary(data$errZad2)
