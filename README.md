# Stock-Tracker
This program receives user-inputted monthly stock prices, calculates their average, fluctuation width and mean, and recommends a buying decision if it meets certain criteria

Stock input will be regulated by a sentinel controlled loop (-1)

**Variables** <br>
To calculate average, total sum of stocks will be divided by number of stocks

To calculate fluctuation width, we determine the max and min stock prices, and find their difference

To calculate fluctuation mean, we first determine _change squared_ between all consecutive stock prices (the difference between each stock price and square it), then we accumulate the sum of all _changes squared_, and divide it by the total number of stocks, after that, we once again square the result to get the fluctuation mean <br>
**Example** <br>
stock1 = 10  
stock2 = 20  
change = 10  
change squared = 100  
cumulative = 100  
number of stocks = 2  

// loop 2  
stock1 = 20 // re-assing from stock2  
stock2 = 15 // new input  
change = 5  
change squared = 25  
cumulative = 125  
number of stocks = 3  

// fluctuation mean  
fm = cumulative / number of stocks  
fm = fm * fm (squared)  

**Buying decision**  
A buying recommendation will be printed only if the last stock price is lower than the avg price AND (either fluctuation width is lower than 1/3 of avg OR fluctuation mean is lower than 1/3 of avg)




