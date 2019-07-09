# 2016 Mathematical Contest in Modeling, Consortium for Mathematics and Its Applications (Question A)
This project is finished by a group of 3 students within 96 hours, my contributions include participating modeling and summarizing our ideas (writing paper). Our solution was selected as Meritorious Winner (Top 8%). The solution paper is here : [Link is here](https://github.com/GAOYUEtianc/2016MCM/mcm_nm/49267.pdf)

# Question Description: 


A person fills a bathtub with hot water from a single faucet and settles into the bathtub to cleanse
and relax. Unfortunately, the bathtub is not a spa-style tub with a secondary heating system and
circulating jets, but rather a simple water containment vessel. After a while, the bath gets
noticeably cooler, so the person adds a constant trickle of hot water from the faucet to reheat the
bathing water. The bathtub is designed in such a way that when the tub reaches its capacity,
excess water escapes through an overflow drain.

Develop a model of the temperature of the bathtub water in space and time to determine the best
strategy the person in the bathtub can adopt to keep the temperature even throughout the bathtub
and as close as possible to the initial temperature without wasting too much water.

Use your model to determine the extent to which your strategy depends upon the shape and
volume of the tub, the shape/volume/temperature of the person in the bathtub, and the motions
made by the person in the bathtub. If the person used a bubble bath additive while initially filling
the bathtub to assist in cleansing, how would this affect your model’s results?

In addition to the required one-page summary for your MCM submission, your report must
include a one-page non-technical explanation for users of the bathtub that describes your strategy
while explaining why it is so difficult to get an evenly maintained temperature throughout the
bath water.

# Main Idea of Our Solution
## Key Words : Heat Expansion; Liquid Cell; ODE; Thermal Field
In order to evaluate the temperature distribution along time parameter, our model treats
water as finite tiny cells firstly and calculates the temperature relation among these cells
in a unit heat transfer process. Under such assumptions, the temperature of hot water
from faucet, heat transfer coefficient between air and water (take bubble into consideration)
and how much water added are variables that will be modified to obtain their
influence on the thermal field. In particular, the model can not only simulate the thermal
field in steady state but also at any time. Through the regression analysis method, the
basic relationships between each variable are found.

Then we made a correction depending on the mobility of water, and further considered
the human motion to improve this model. Finally, the interactional relationships
among the yield of water, comfort degree (measured by mean and standard deviation of
water temperature) and time can be known. Since different people have different preference
between saving water and bathing in a uniform temprature, different strategies are
given depending on the significance of these two expectations.

During model evaluation, strengths and weaknesses are analyzed. Error analysis and
suggestions are also been discussed in this part.
