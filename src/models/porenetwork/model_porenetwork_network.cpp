#include "model_porenetwork.hpp"

// 1d->2d index
#define idx2(i, j, ldi) ((i * ldi) + j)

// 1d->3d index
#define idx3(i, j, k, ldi1, ldi2) (k + (ldi2 * (j + ldi1 * i)))

/** \brief hgf::models::uniform_porenetwork::build_uniform_network builds the degrees of freedom and initializes the peremability vector for a uniform porenetwork.
 *
 * @param[in] par - parameters struct containing problem information.
 * @param[in] n_pores_x - number of pores in the x-direction.
 * @param[in] n_pores_y - number of pores in the y-direction.
 * @param[in] n_pores_z - number of pores in the z-direction.
 */
void
hgf::models::uniform_porenetwork::build_uniform_network(const parameters& par, int n_pores_x, int n_pores_y, int n_pores_z)
{
  if (par.dimension == 2) {
    double dx, dy;
    dx = par.length / (n_pores_x - 1);
    dy = par.width / (n_pores_y - 1);
    int n_pores = n_pores_x * n_pores_y;

    pressure.resize(n_pores);
    permeability.resize(n_pores * 4);

    for (int jj = 0; jj < n_pores_y; jj++) {
      for (int ii = 0; ii < n_pores_x; ii++) {
        pressure[idx2(jj, ii, n_pores_x)].coords[0] = dx * ii;
        pressure[idx2(jj, ii, n_pores_x)].coords[1] = dy * jj;
        pressure[idx2(jj, ii, n_pores_x)].neighbors[0] = jj ? idx2((jj - 1), ii, n_pores_x) : -1;
        pressure[idx2(jj, ii, n_pores_x)].neighbors[1] = (ii < n_pores_x - 1) ? idx2(jj, (ii + 1), n_pores_x) : -1;
        pressure[idx2(jj, ii, n_pores_x)].neighbors[2] = (jj < n_pores_y - 1) ? idx2((jj + 1), ii, n_pores_x) : -1;
        pressure[idx2(jj, ii, n_pores_x)].neighbors[3] = ii ? idx2(jj, (ii - 1), n_pores_x) : -1;
        if (!ii || !jj || (ii == n_pores_x - 1) || (jj == n_pores_y - 1)) pressure[idx2(jj, ii, n_pores_x)].doftype = 1;
        else pressure[idx2(jj, ii, n_pores_x)].doftype = 0;
      }
    }

  }
  else {
    double dx, dy, dz;
    dx = par.length / (n_pores_x - 1);
    dy = par.width / (n_pores_y - 1);
    dz = par.height / (n_pores_z - 1);
    int n_pores = n_pores_x * n_pores_y * n_pores_z;

    pressure.resize(n_pores);
    permeability.resize(n_pores * 6);

    for (int kk = 0; kk < n_pores_z; kk++) {
      for (int jj = 0; jj < n_pores_y; jj++) {
        for (int ii = 0; ii < n_pores_x; ii++) {
          pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].coords[0] = dx * ii;
          pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].coords[1] = dy * jj;
          pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].coords[2] = dz * kk;
          pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].neighbors[0] = jj ? idx3(kk, (jj - 1), ii, n_pores_y, n_pores_x) : -1;
          pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].neighbors[1] = (ii < n_pores_x - 1) ? idx3(kk, jj, (ii + 1), n_pores_y, n_pores_x) : -1;
          pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].neighbors[2] = (jj < n_pores_y - 1) ? idx3(kk, (jj + 1), ii, n_pores_y, n_pores_x) : -1;
          pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].neighbors[3] = ii ? idx3(kk, jj, (ii - 1), n_pores_y, n_pores_x) : -1;
          pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].neighbors[4] = kk ? idx3((kk - 1), jj, ii, n_pores_y, n_pores_x) : -1;
          pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].neighbors[5] = (kk < n_pores_z - 1) ? idx3((kk + 1), jj, ii, n_pores_y, n_pores_x) : -1;
          if (!ii || !jj || !kk || (ii == n_pores_x - 1) || (jj == n_pores_y - 1) || (kk == n_pores_z - 1)) pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].doftype = 2;
          else pressure[idx3(kk, jj, ii, n_pores_y, n_pores_x)].doftype = 0;
        }
      }
    }

  }

}

