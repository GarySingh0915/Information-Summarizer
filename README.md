# Information-Summarizer
Problem: Summarizing large amounts of data has, since the 1950’s, been a task relegated to computers.
Our problem is to develop a program that will summarize selected information from a relatively
large list of artificial census information.

The Assignment: Design, develop and test an Object-Oriented C++ program that summarizes certain
aspects of data from a collection of people. The data for the collection is provided in a commaseparated-values (csv) file named “FakeNames.csv”. Your solution must save the following
summary information from the collection to a text file named “summary.txt”.

• Total count of all records in the collection (each record contains data for one person)

• Full name and birthdate of the first person and last person in the collection

• A count of the unique first names in the collection

• A list of the 100 most common first names of all people in the collection. The list must be in
descending order of occurrence, with the most common first name first, four names per line of
output, formatted as “firstname : count”

• A count of the unique city names in the collection

• A list of the 100 most common city names of all the people in the collection. The list must be in
descending order of occurrence, with the most common city name first, three names per line of
output, formatted as “cityname : count”
Discussion: Your program must create a Person class to hold information about one person. Consider the
following issues as you prepare your solution.

• The information that the program retains for each person includes their name, mailing address,
phone number, and more, according to the csv file provided to you. All fields present in the data file
must be included as instance variables in the Person class.

• There are 6,000 records in the csv data file. Use a vector to hold the collection of Person variables.

• The program must load all data from the csv file into the collection of Person variables and then
output the summary information listed above to the designated text file.

• All output must be formatted into columns similar to that in the HW6_Sample.txt file
