Gauss <- read.csv("C:\\Users\\Szymon\\OneDrive\\Pulpit\\2rok4sem\\AlgorytmyNumeryczne\\num3\\Gauss.csv")
GaussSeidel <- read.csv("C:\\Users\\Szymon\\OneDrive\\Pulpit\\2rok4sem\\AlgorytmyNumeryczne\\num3\\GaussSeidel.csv")
Jacobs <- read.csv("C:\\Users\\Szymon\\OneDrive\\Pulpit\\2rok4sem\\AlgorytmyNumeryczne\\num3\\Jacobs.csv")



plot(Gauss$n, Gauss$error, type = "b", ylab = "Errors", xlab ="N")
lines(GaussSeidel$n, GaussSeidel$error, col="blue", type="b")
lines(Jacobs$n, Jacobs$error, col="red", type="b")

plot(Gauss$n, log(Gauss$time), type = "b", ylab = "Time in NanoSec", xlab ="N")
lines(GaussSeidel$n, log(GaussSeidel$time), col="blue", type="b")
lines(Jacobs$n, log(Jacobs$time), col="red", type="b")


