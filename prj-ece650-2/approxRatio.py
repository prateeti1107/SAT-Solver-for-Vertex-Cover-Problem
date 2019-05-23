import matplotlib.pyplot as plt

import numpy as np
fig, ax = plt.subplots()

time = [2,4,6,8,10,12,14,16]
approxRatioCNF = [1,1,1,1,1,1,1,1]
approxRatioApproxVc1 = [1,1,1,1,1,1.03,1.01,1]
approxRatioApproxVc2 = [2,1.36,1.9,1.5,2,1.8,1.33,1.75]

upperBoundcnf = [1,1,1,1,1,1,1,1]
lowerBoundcnf = [1,1,1,1,1,1,1,1]

upperBoundapprox1 = [1,1,1,1,1,1.1,1.5,1]
lowerboundapprox1 = [1,1,1,1,1,1.01,1.01,1]

upperboundapprox2 = [2.1,1.4,2,1.7,2,2,1.5,1.9]
lowerboundapprox2 = [1.8,1.2,1.7,1.2,1.8,1.5,1.1,1.5]

upperBoundApproxVc1 = [0.0249450,0.0279012,0.042824,0.046803,0.062903,0.082101,0.109011,0.174002]
lowerBoundApproxVc1 = [0.0240101,0.0265233,0.041101,0.046012,0.062010, 0.081901, 0.108020, 0.173901]

upperBoundApproxVc2 = [0.0219345,0.022902,0.038233,0.045930,0.05390,0.066902,0.078902,0.15123]
lowerBoundApproxVc2 = [0.0210413,0.021901,0.037902,0.044901,0.05301,0.06580,0.078100,0.13903]

tds1 = []
stds2 = []
stds3 = []

for i in xrange(0, 8):
    means1 = []
    means2 = []
    means3 = []

    means1.append(upperBoundcnf[i])
    means1.append(lowerBoundcnf[i])

    means2.append(upperBoundapprox1[i])
    means2.append(lowerboundapprox1[i])

    means3.append(upperboundapprox2)
    means3.append(lowerboundapprox2)

    stds1.append(np.std(means1))
    stds2.append(np.std(means2))
    stds3.append(np.std(means3))
    means1 = []
    means2 = []
    means3 = []

plt.title("Approximation Ratio Analysis")
plt.xlabel("Number of Vertices", fontsize = "15")
plt.ylabel("Approximation Ratio", fontsize = "15")

plt.plot(time,approxRatioCNF, label = "CNF-SAT")
plt.plot(time,approxRatioApproxVc1, label = "APPROX-VC-1")
plt.plot(time,approxRatioApproxVc2, label = "APPROX-VC-2")

ax.errorbar(time,approxRatioCNF, stds1, fmt = 'o',marker='.',capsize = 3, label = "Standard Deviation for CNF-SAT")
ax.errorbar(time,approxRatioApproxVc1, stds2, fmt = 'o',marker='.',capsize = 3, label = "Standard Deviation for Approx-Vc-1")
ax.errorbar(time,approxRatioApproxVc2, stds3, fmt = 'o',marker='.',capsize = 3, label = "Standard Deviation for Approx-Vc-2")

plt.legend(loc='lower left',prop={'size': 4}, fontsize = 'small')
plt.show()
