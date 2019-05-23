import matplotlib.pyplot as plt

import numpy as np
fig, ax = plt.subplots()
vertices = [2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
cnfSat=[[0.092199,0.142328,0.103849,0.096178,0.093159],
[0.217927,0.219856,0.219786,0.239447,0.237316],
[0.6332,0.6366,0.608601,0.6366,0.61668],
[0.737918,0.743689,0.743879,0.680629,0.821767],
[0.927486,0.906715,0.931986,1.27973,0.921405],
[1.29857,1.70686,1.71886,1.70635,1.5490],
[3.8777,3.78631,3.52379,3.75156,2.02873],
[3.53812,5.6366,6.44201,5.6003,5.83193],
[20.5368,21.3618,20.7589,17.4829,9.83235],
[23.6883,17.297,22.2177,17.4967,16.6443],
[339.607,310.897,468.893,527.205,518.784],
[627.462,884.834,538.623,472.1501,1011.81],
[932.084,6525.1,14702.7,489.982,30707.9],
[13905.9,22432.8,21711.25,13711.02,20699.2],
[31694.1,29438.4,21454.8,18147,35230.7]
]

meanArr = []
stdArr = []

for i in range(0, 15):
    #print (cnfSat[i])
    meanArr.append(np.mean(cnfSat[i]))
    stdArr.append(np.std(cnfSat[i]))

plt.title("CNF-SAT")
plt.xlabel("Number of Vertices", fontsize = "15")
plt.ylabel("Running Time(ms)", fontsize = "15")

plt.plot(vertices,meanArr, label = "CNF-SAT")
ax.errorbar(vertices,meanArr, stdArr, fmt = 'o',marker='.',capsize = 3, label = "Standard Deviation for CNF-SAT")

plt.legend(loc='upper left')
plt.show()
