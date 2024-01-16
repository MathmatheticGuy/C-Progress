import csv

data = [
    ['Name', 'Age', 'City'],
    ['John', '25', 'New York'],
    ['Anna', '30', 'London'],
    ['Mike', '35', 'Berlin']
]

with open('FileHolder/output.csv', 'w', newline='') as file:
    writer = csv.writer(file)
    writer.writerows(data)