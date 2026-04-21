IN104: Monte Carlo Simulation of the Ising Model
Welcome to Timothée & Riyad's project "Monte Carlo Simulation of the Ising Model"

The first step of our project (April 14th) was to familiarize ourselves with the rand() function in C, which will be very useful later on for randomly simulating states (-1 or 1).
The teacher then suggested we start with 3 different exercises: Approximating pi in 2 different ways and calculating a "complicated" integral.

A first way is to randomly place points on a 1x1 square and count the ones that fall within the inscribed circle of radius 1/2. This way, we know that (Number of points in the circle) / (Total number of placed points) = pi/4, the area of the inscribed circle. We then just have to isolate pi from this!

The second method is not much more complicated, as it uses the fact that the area of a standard normal Gaussian curve is sqrt(pi). So, we again place points randomly and count the ones UNDER the curve (i.e., the (x,y) coordinates where y < exp(-x²)).

The last exercise is very similar to what we just did with the Gaussian, except that we don't know the theoretical value of an integral, so we approximate it numerically using this method.

It was a great learning experience, and we really enjoyed getting our hands dirty with our first codes using rand().

On April 21st, we wrote a function to calculate the autocorrelation, as well as another function to calculate the energy of the configuration after properly defining the "square lattice".
