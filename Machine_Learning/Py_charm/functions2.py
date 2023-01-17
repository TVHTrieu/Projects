import sys

def ReadData(fileName):
    # Read the file, splitting by lines
    f = open(fileName, 'r')
    lines = f.read().splitlines()
    f.close()

    items = []

    for i in range(0, len(lines)):
        line = lines[i].split(',')
        itemFeatures = []

        for j in range(len(line) - 1):

            v = float(line[j])

            itemFeatures.append(v)

        items.append(itemFeatures)

    return items


def FindColMinMax(items):

    min = items[0]
    max = items[-1]
    for item in items:
        for j in range(len(item)):
            if(item[j] < min[j]):
                min[j] = item[j]

            if(item[j] > max[j]):
                max[j] = item[j]


    return min, max