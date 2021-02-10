#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

// TODO error handling
// distance calculation

void startUp() {
  std::cout << "Welcome to Artillery.\n" << 
    "You are in the middle of a war and being charged by thousands of enemies.\n" <<
    "You have one cannon, which you can shoot at any angle.\n" << 
    "You only have 10 cannonballs for this target...\n" <<
    "Let's begin...\n";
}

namespace {
  const int kMinDist = 10;
  const double kVelocity = 200.0;
  const double kGravity = 32.2;
};

int distance(double in_angle) { 
  double air_time = (2.0*kVelocity*std::sin(in_angle))/kGravity;
  return std::round((kVelocity*std::cos(in_angle))*air_time);
}

bool isUnderHit(int cannon_dist, int target_dist) {
  return cannon_dist-target_dist < -5;
}

bool isOverHit(int cannon_dist, int target_dist) {
  return cannon_dist-target_dist > 5;
}

int Fire(const int nshots) {
  srand(time(NULL));
  int dist = rand()%500 + kMinDist;
  std::cout << "The enemy is " << dist << " feet away!\n";
  int done = 0;
  int nhits = 0;
  int nkilled = 0;
  do {
    double angle;
    std::cout << "What angle? ";
    std::cin >> angle;
    if (std::cin.eof()) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      return -1;
    }
    angle = (angle*3.1415)/180.0;
    int cannon_dist = distance(angle); 
    if (cannon_dist == -1) {
      std::cin.clear();
      std::cin.ignore(1000, '\n');
      continue;
    }
    if (isUnderHit(cannon_dist, dist)) {
      std::cout << "You under shot by " << dist-cannon_dist << '\n';
      ++nhits;
    } else if (isOverHit(cannon_dist, dist)) {
      std::cout << "You over shot by " << cannon_dist-dist << '\n';
      ++nhits;
    } else {
      ++nhits;
      std::cout << "You hit him!!!\n";
      std::cout << "It took you " << nhits << " shots\n";
      done = 1;
      ++nkilled;
    }
  } while (nhits<=nshots && done != 1);
  std::cout << "You killed " << nkilled << " of the enemy\n" << std::endl; 
  return nkilled;
}

int main() {
  startUp();
  int killed = 0;
  char done;
  int nshots = 10;
  do {
    std::cout << std::endl;
    killed = Fire(nshots);    
    std::cout << "I see another one, are you ready? (Y/N) " << std::endl;
    if (!(std::cin >> done)) {
      if (std::cin.eof()) {
	break;
      }
      std::cout << "type 'y' or 'n': ";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    } 
  } while (done != 'n');

  return 0;
}
