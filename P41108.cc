#include "Player.hh"
#include <queue>

/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME Zeus2


struct PLAYER_NAME : public Player {
  	/**
  	* Factory: returns a new instance of this class.
  	* Do not modify this function.
 	*/
 	static Player* factory () {
    return new PLAYER_NAME;
  	}

  	/**
  	* Types and attributes for your player can be defined here.
  	*/

  	typedef vector<int> VI;
  	typedef vector<VI>  VVI;
	
	typedef vector <char>VC;
	typedef vector <VC>VVC;

	typedef vector <bool>VB;
	typedef vector <VB>VVB;

	// BFS to search for the closest city
	pair<Dir, int> buscar_ciudad(int i, int j) {
		queue <pair < pair<int, int>, pair<Dir, int>>> queue; // cola de posiciones, direcciones y distancias
		queue.push(make_pair(make_pair(i, j), (make_pair(NONE, 0)))); // insertamos en la cola la posicion, la direccion y la distancia iniciales
		VVB visited(rows(), VB(cols(), false));    // matrix de visitados de tamaño rows * cols
		visited[i][j] = true;

		int x, y, dis;
		Dir dir;
		bool first = true;

		while (!queue.empty()) {
			dir = (queue.front().second).first;   // direccion
			dis = (queue.front().second).second;  // distancia
			x = (queue.front().first).first;
			y = (queue.front().first).second;
			queue.pop();
			
			//bottom
			if(first) dir = BOTTOM;
			if (mover_ciudad(x+1, y, visited, queue, dir, dis)) return make_pair(dir, dis);
			
			//top
			if(first) dir = TOP;
			if (mover_ciudad(x-1, y, visited, queue, dir, dis)) return make_pair(dir, dis);

			//right
			if(first) dir = RIGHT;
			if (mover_ciudad(x, y+1, visited, queue, dir, dis)) return make_pair(dir, dis);

			//left
			if(first) dir = LEFT;
			if (mover_ciudad(x, y-1, visited, queue, dir, dis)) return make_pair(dir, dis);

			first = false;
		}
		return make_pair(NONE, 2147483647); //en caso de que no encuentre ciudad nos quedamos parados
	}
	bool mover_ciudad(int x, int y, VVB& visited, queue <pair < pair<int, int>, pair<Dir, int>>> &q, Dir dir, int dis) {
		if (pos_ok(x, y) and !visited[x][y]) {
			if (cell(x, y).type == CITY and city_owner(cell(x, y).city_id) != me()) return true;
			visited[x][y] = true;
			if (cell(x, y).type != WALL and cell(x, y).unit_id == -1) {
				q.push(make_pair(make_pair(x, y), make_pair(dir, dis+1)));
			}
		}
		return false;
	}

	// BFS to search for the closest path
	pair<Dir, int> buscar_camino(int i, int j) {
		queue <pair < pair<int, int>, pair<Dir, int>>> queue; // cola de posiciones, direcciones y distancias
		queue.push(make_pair(make_pair(i, j), (make_pair(NONE, 0)))); // insertamos en la cola la posicion, la direccion y la distancia iniciales
		VVB visited(rows(), VB(cols(), false));    // matrix de visitados de tamaño rows * cols
		visited[i][j] = true;

		int x, y, dis;
		Dir dir;
		bool first = true;

		while (!queue.empty()) {
			dir = (queue.front().second).first;   //direccion
			dis = (queue.front().second).second; //distancia
			x = (queue.front().first).first;
			y = (queue.front().first).second;
			queue.pop();
			
			//bottom
			if(first) dir = BOTTOM;
			if (mover_camino(x+1, y, visited, queue, dir, dis)) return make_pair(dir, dis);
			
			//top
			if(first) dir = TOP;
			if (mover_camino(x-1, y, visited, queue, dir, dis)) return make_pair(dir, dis);

			//right
			if(first) dir = RIGHT;
			if (mover_camino(x, y+1, visited, queue, dir, dis)) return make_pair(dir, dis);

			//left
			if(first) dir = LEFT;
			if (mover_camino(x, y-1, visited, queue, dir, dis)) return make_pair(dir, dis);

			first = false;
		}
		return make_pair(NONE, 2147483647); //en caso de que no encuentre ciudad nos quedamos parados
	}
	bool mover_camino(int x, int y, VVB& visited, queue <pair < pair<int, int>, pair<Dir, int>>> &q, Dir dir, int dis) {
		if (pos_ok(x, y) and !visited[x][y]) {
			if (cell(x, y).type == PATH and path_owner(cell(x, y).path_id) != me()) return true;
			visited[x][y] = true;
			if (cell(x, y).type != WALL and cell(x, y).unit_id == -1) {
				q.push(make_pair(make_pair(x, y), make_pair(dir, dis+1)));
			}
		}
		return false;
	}

	// BFS to search for the closest player
	pair<Dir, int> buscar_jugador(int i, int j) {
		queue <pair < pair<int, int>, pair<Dir, int>>> queue; // cola de posiciones, direcciones y distancias
		queue.push(make_pair(make_pair(i, j), (make_pair(NONE, 0)))); // insertamos en la cola la posicion, la direccion y la distancia iniciales
		VVB visited(rows(), VB(cols(), false));    // matrix de visitados de tamaño rows * cols
		visited[i][j] = true;

		int x, y, dis;
		Dir dir;
		bool first = true;

		while (!queue.empty()) {
			dir = (queue.front().second).first;  //direccion
			dis = (queue.front().second).second; //distancia
			x = (queue.front().first).first;
			y = (queue.front().first).second;
			queue.pop();
			
			//bottom
			if(first) dir = BOTTOM;
			if (mover_jugador(x+1, y, visited, queue, dir, dis)) return make_pair(dir, dis);
			
			//top
			if(first) dir = TOP;
			if (mover_jugador(x-1, y, visited, queue, dir, dis)) return make_pair(dir, dis);

			//right
			if(first) dir = RIGHT;
			if (mover_jugador(x, y+1, visited, queue, dir, dis)) return make_pair(dir, dis);

			//left
			if(first) dir = LEFT;
			if (mover_jugador(x, y-1, visited, queue, dir, dis)) return make_pair(dir, dis);

			first = false;
		}
		return make_pair(NONE, 2147483647); //en caso de que no encuentre ciudad nos quedamos parados
	}
	bool mover_jugador(int x, int y, VVB& visited, queue <pair < pair<int, int>, pair<Dir, int>>> &q, Dir dir, int dis) {
		if (pos_ok(x, y) and !visited[x][y]) {
			if (cell(x, y).unit_id != -1 and unit(cell(x, y).unit_id).player != me()) return true;
			visited[x][y] = true;
			if (cell(x, y).type != WALL and cell(x, y).unit_id == -1) {
				q.push(make_pair(make_pair(x, y), make_pair(dir, dis+1)));
			}
		}
		return false;
	}

  	/**
   	* Play method, invoked once per each round.
  	*/
  	virtual void play () {
		VI U = my_units(me()); // Get the id's of my units.
	  	int n = U.size();
	  	VI perm = random_permutation(n);
	  	for (int i = 0; i < n; ++i) {
			// We process the units in random order.
		 	int id = U[perm[i]];
		  	Unit u = unit(id);

			//busca a la unidad enemiga mas cercana
			pair<Dir, int> search_player = buscar_jugador(u.pos.i, u.pos.j);
			Dir dir_player = search_player.first;
			int dis_player = search_player.second;
			
			if(dis_player <= 2) move(id, dir_player);
			else {
				//busca la ciudad mas cercana
				pair<Dir, int> search_city = buscar_ciudad(u.pos.i, u.pos.j);
				Dir dir_city = search_city.first;
				int dis_city = search_city.second;

				//busca el camino mas cercano
				pair<Dir, int> search_path = buscar_camino(u.pos.i, u.pos.j);
				Dir dir_path = search_path.first;
				int dis_path = search_path.second;

				if (dis_city <= dis_path) move(id, dir_city);
				else move(id, dir_path);
			}
			
			// If nearly out of time, do nothing.
			double st = status(me());
			if (st >= 0.95) return;
		}
 	}	
};

			
/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);

