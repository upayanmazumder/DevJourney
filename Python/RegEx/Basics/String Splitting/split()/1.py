text = 'Python is easy'
print(text.split())
print(text.split(' '))
print(text.split('is'))
print(text.split('*'))

# Output:
#####################
# ['Python', 'is', 'easy']
# ['Python', 'is', 'easy']
# ['Python ', ' easy']
# ['Python is easy']