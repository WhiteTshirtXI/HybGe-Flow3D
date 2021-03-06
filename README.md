# HybGe-Flow3D #

HybGe-Flow3D is a library designed for solving multiscale fluid flow problems in complex, uncertain 3D and 2D geometries.

This software is developed and maintained by Numerical Solutions, Inc.

The first version of this software was developed under the partial support of the National Science
Foundation on the projects NSF DMS-1115827 "Hybrid modeling in porous media" (PI: M. Peszynska)
and NFS DMS-1522734 "Phase transitions in porous media across multiple scales" (PI: M. Peszynska).

### Documentation ###

Please find detailed documentation at www.numericalsolutions.org/doc/hybge-flow3d

### License ###

HybGe-Flow3D Copyright (C) Numerical Solutions, Inc.

This problem is free software; you can redistribute and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or any later version.

This software is distributed AS IS and
WITHOUT ANY WARRANTY.

A copy of the GNU General Public License is included in the source and
can also be found at http://www.gnu.org/licenses/.

### Citation ###

Publications making use of HybGe-Flow3D should cite this software package. An example citation is given as:

    Costa, T., "HybGe-Flow3D", Package Version 2.1.0,
    http://github.com/numsol/HybGe-Flow3D.

### Contact ###

Timothy B. Costa, timothy.costa@numericalsolutions.org

### Change Log ###

Version 2.1.0
- Add linear solver controls to parameters struct. Requires Parameters.dat file include:
    - solver_max_iterations
    - solver_absolute_tolerance
    - solver_relative_tolerance
    - solver_verbose
 - Add function hgf::models::stokes::write_state.
    - Writes to file (name argument appended with '.dat') the state of the Stokes system, storing all degree of freedom coordinates and values.
 - Correct upscaled permeability functions to account for presence of an immersed boundary. Requires API change to include pressure_ib_list argument in functions:
    - hgf::multiscale::flow::compute_permeability_x
    - hgf::multiscale::flow::compute_permeability_y
    - hgf::multiscale::flow::compute_permeability_z
    - hgf::multiscale::flow::compute_permeability_tensor
 - Example geometries given descriptive names.
 - Add example geometry 'immersed_circles_2d' identical to voxel_quadrilaterals but with geometry entirely enforced via immersed boundary.
