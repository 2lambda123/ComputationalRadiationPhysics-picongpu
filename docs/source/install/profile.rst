.. _install-profile:

.. seealso::

   You need to have all :ref:`dependencies installed <install-dependencies>` to complete this chapter.

picongpu.profile
================

.. sectionauthor:: Axel Huebl, Klaus Steiniger

We recommend to use a ``picongpu.profile`` file, located directly in your ``$HOME/`` directory,
to set up the environment within which PIConGPU will run by conviently performing

.. code-block:: bash

   source $HOME/picongpu.profile

on the command line after logging in to a system.
PIConGPU is shipped with a number of ready-to-use profiles for different systems which are located in
``etc/picongpu/<cluster>-<institute>/`` within PIConGPU's main folder.
Have a look into this directory in order to see for which HPC systems profiles are already available.
If you are working on one of these systems, just copy the respective ``*_picongpu.profile.example``
from within this directory into your ``$HOME`` and make the necessary changes, such as e-mail address
or PIConGPU source code location defined by ``$PICSRC``.
If you are working on an HPC system for which no profile is available, feel free to create one and
contribute it to PIConGPU by opening a pull request.

A selection of available profiles is presented below.
Beware, these may not be up-to-date with the latest available software on the respective system,
as we do not have continuous access to all of these.


Your Workstation
----------------

This is a very basic ``picongpu.profile`` enabling compilation on CPUs by setting the OpenMP backend, declaring commonly required directories,
and providing default parameters for :ref:`TBG <usage-tbg>`.

.. literalinclude:: profiles/bash/bash_picongpu.profile.example
   :language: bash

Crusher (ORNL)
--------------

**System overview:** `link <https://docs.olcf.ornl.gov/systems/crusher_quick_start_guide.html#system-overview>`_

**Production directory:** usually ``$PROJWORK/$proj/`` (`link <https://docs.olcf.ornl.gov/systems/crusher_quick_start_guide.html#data-and-storage>`_).
Note that ``$HOME`` is mounted on compute nodes as read-only.

For this profile to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` and install :ref:`PNGwriter and openPMD <install-dependencies>` manually.

MI250X GPUs using hipcc (recommended)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/crusher-ornl/batch_hipcc_picongpu.profile.example
   :language: bash

MI250X GPUs using craycc
^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/crusher-ornl/batch_craycc_picongpu.profile.example
  :language: bash

Hemera (HZDR)
-------------

**System overview:** `link (internal) <https://www.hzdr.de/db/Cms?pOid=29813>`_

**User guide:** *None*

**Production directory:** ``/bigdata/hplsim/`` with ``external/``, ``scratch/``, ``development/`` and ``production/``

Profile for HZDR's home cluster hemera.
Sets up software environment, i.e. providing libraries to satisfy PIConGPU's dependencies, by loading modules,
setting common paths and options, as well as defining the ``getDevice()`` and ``getNode()`` aliases.
The latter are shorthands to request resources for an interactive session from the batch system.
Together with the `-s bash` option of :ref:`TBG <usage-tbg>`, these allow to run PIConGPU interactively on an HPC system.


For this profile to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` manually.

Queue: defq (2x Intel Xeon Gold 6148, 20 Cores + 20 HyperThreads/CPU)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/hemera-hzdr/defq_picongpu.profile.example
   :language: bash

Queue: gpu (4x NVIDIA P100 16GB)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/hemera-hzdr/gpu_picongpu.profile.example
   :language: bash

Queue: fwkt_v100 (4x NVIDIA V100 32GB)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/hemera-hzdr/fwkt_v100_picongpu.profile.example
   :language: bash

Queue: k20 (4x Nvidia K20m GPUs 4.7GB)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/hemera-hzdr/k20_picongpu.profile.example
   :language: bash

Queue: k80 (8x NVIDIA K80 12GB)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/hemera-hzdr/k80_picongpu.profile.example
   :language: bash

Summit (ORNL)
-------------

**System overview:** `link <https://www.olcf.ornl.gov/olcf-resources/compute-systems/summit/>`_

**User guide:** `link <https://www.olcf.ornl.gov/for-users/system-user-guides/summit/>`_

**Production directory:** usually ``$PROJWORK/$proj/`` (`link <https://www.olcf.ornl.gov/for-users/system-user-guides/summit/summit-user-guide/#file-systems>`_).
Note that ``$HOME`` is mounted on compute nodes as read-only.

For this profile to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` and install :ref:`PNGwriter <install-dependencies>` manually.

V100 GPUs (recommended)
^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/summit-ornl/gpu_picongpu.profile.example
   :language: bash

Piz Daint (CSCS)
----------------

**System overview:** `link <https://www.cscs.ch/computers/piz-daint/>`_

**User guide:** `link <https://user.cscs.ch/>`_

**Production directory:** ``$SCRATCH`` (`link <https://user.cscs.ch/storage/file_systems/>`_).

For this profile to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` and install :ref:`boost, zlib, libpng, c-blosc, PNGwriter and ADIOS <install-dependencies>` manually.

.. note::

   The MPI libraries are lacking Fortran bindings (which we do not need anyway).
   During the install of ADIOS, make sure to add to ``configure`` the ``--disable-fortran`` flag.

.. note::

   Please find a `Piz Daint quick start from August 2018 here <https://gist.github.com/ax3l/68cb4caa597df3def9b01640959ea56b>`_.

.. literalinclude:: profiles/pizdaint-cscs/picongpu.profile.example
   :language: bash

Taurus (TU Dresden)
-------------------

**System overview:** `link <https://tu-dresden.de/zih/hochleistungsrechnen/hpc>`_

**User guide:** `link <https://doc.zih.tu-dresden.de/hpc-wiki/bin/view/Compendium/SystemTaurus>`_

**Production directory:** ``/scratch/$USER/`` and ``/scratch/$proj/``

For these profiles to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` and install :ref:`PNGwriter <install-dependencies>` manually.

Queue: gpu1 (Nvidia K20x GPUs)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/taurus-tud/k20x_picongpu.profile.example
   :language: bash

Queue: gpu2 (Nvidia K80 GPUs)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/taurus-tud/k80_picongpu.profile.example
   :language: bash

Queue: knl (Intel Xeon Phi - Knights Landing)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

For this profile, you additionally need to install your own :ref:`boost <install-dependencies>`.

.. literalinclude:: profiles/taurus-tud/knl_picongpu.profile.example
   :language: bash
   
Queue: ml (NVIDIA V100 GPUs on Power9 nodes)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

For this profile, you additionally need to compile and install everything for the power9-architecture including your own :ref:`boost <install-dependencies>`, :ref:`HDF5 <install-dependencies>`, c-blosc and :ref:`ADIOS <install-dependencies>`.

.. note::

   Please find a `Taurus ml quick start here <https://gist.github.com/steindev/cc02eae81f465833afa27fc8880f3473>`_.

.. note::
   
   You need to compile the libraries and PIConGPU on an ``ml`` node since
   only nodes in the ``ml`` queue are Power9 systems.

.. literalinclude:: profiles/taurus-tud/V100_picongpu.profile.example
   :language: bash

Lawrencium (LBNL)
-----------------

**System overview:** `link <http://scs.lbl.gov/Systems>`_

**User guide:** `link <https://sites.google.com/a/lbl.gov/high-performance-computing-services-group/lbnl-supercluster/lawrencium>`_

**Production directory:** ``/global/scratch/$USER/``

For this profile to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` and install :ref:`boost and PNGwriter <install-dependencies>` manually.
Additionally, you need to make the ``rsync`` command available as written below.

.. literalinclude:: profiles/lawrencium-lbnl/picongpu.profile.example
   :language: bash

Cori (NERSC)
------------

**System overview:** `link <https://www.nersc.gov/users/computational-systems/cori/configuration/>`_

**User guide:** `link <https://docs.nersc.gov/>`_

**Production directory:** ``$SCRATCH`` (`link <https://www.nersc.gov/users/storage-and-file-systems/>`_).

For these profiles to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` and install :ref:`PNGwriter <install-dependencies>` manually.

Queue: regular (Intel Xeon Phi - Knights Landing)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/cori-nersc/knl_picongpu.profile.example
   :language: bash

Queue: dgx (DGX - A100)
^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/cori-nersc/a100_picongpu.profile.example
   :language: bash

Draco (MPCDF)
-------------

**System overview:** `link <https://www.mpcdf.mpg.de/services/computing/draco/about-the-system>`_

**User guide:** `link <https://www.mpcdf.mpg.de/services/computing/draco>`_

**Production directory:** ``/ptmp/$USER/``

For this profile to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` and install :ref:`libpng and PNGwriter <install-dependencies>` manually.

.. literalinclude:: profiles/draco-mpcdf/picongpu.profile.example
   :language: bash

D.A.V.I.D.E (CINECA)
--------------------

**System overview:** `link <http://www.hpc.cineca.it/content/davide>`_

**User guide:** `link <https://wiki.u-gov.it/confluence/display/SCAIUS/UG3.2%3A+D.A.V.I.D.E.+UserGuide>`_

**Production directory:** ``$CINECA_SCRATCH/`` (`link <https://wiki.u-gov.it/confluence/display/SCAIUS/UG2.4%3A+Data+storage+and+FileSystems>`_)

For this profile to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` manually.

Queue: dvd_usr_prod (Nvidia P100 GPUs)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/davide-cineca/gpu_picongpu.profile.example
   :language: bash

JURECA (JSC)
------------

**System overview:** `link <http://www.fz-juelich.de/ias/jsc/EN/Expertise/Supercomputers/JURECA/JURECA_node.html>`_

**User guide:** `link <http://www.fz-juelich.de/ias/jsc/EN/Expertise/Supercomputers/JURECA/UserInfo/UserInfo_node.html>`_

**Production directory:** ``$SCRATCH`` (`link <http://www.fz-juelich.de/SharedDocs/FAQs/IAS/JSC/EN/JUST/FAQ_00_File_systems.html?nn=1297148>`_)

For these profiles to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` and install :ref:`PNGwriter and openPMD <install-dependencies>`, for the gpus partition also :ref:`Boost and HDF5 <install-dependencies>`, manually.

Queue: batch (2 x Intel Xeon E5-2680 v3 CPUs, 12 Cores + 12 Hyperthreads/CPU)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/jureca-jsc/batch_picongpu.profile.example
   :language: bash

Queue: gpus (2 x Nvidia Tesla K80 GPUs)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/jureca-jsc/gpus_picongpu.profile.example
   :language: bash

Queue: booster (Intel Xeon Phi 7250-F, 68 cores + Hyperthreads)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/jureca-jsc/booster_picongpu.profile.example
   :language: bash

JUWELS (JSC)
------------

**System overview:** `link <http://www.fz-juelich.de/ias/jsc/EN/Expertise/Supercomputers/JUWELS/JUWELS_node.html>`_

**User guide:** `link <http://www.fz-juelich.de/ias/jsc/EN/Expertise/Supercomputers/JUWELS/UserInfo/UserInfo_node.html>`_

**Production directory:** ``$SCRATCH`` (`link <http://www.fz-juelich.de/ias/jsc/EN/Expertise/Supercomputers/JUWELS/FAQ/juwels_FAQ_node.html#faq1495160>`_)

For these profiles to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` and install :ref:`PNGwriter and openPMD <install-dependencies>`, for the gpus partition also :ref:`Boost and HDF5 <install-dependencies>`, manually.

Queue: batch (2 x Intel Xeon Platinum 8168 CPUs, 24 Cores + 24 Hyperthreads/CPU)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/juwels-jsc/batch_picongpu.profile.example
   :language: bash

Queue: gpus (4 x Nvidia V100 GPUs)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/juwels-jsc/gpus_picongpu.profile.example
   :language: bash

ARIS (GRNET)
------------

**System overview:** `link <http://doc.aris.grnet.gr/>`_

**User guide:** `link <http://doc.aris.grnet.gr/environment/>`_

**Production directory:** ``$WORKDIR`` (`link <http://doc.aris.grnet.gr/system/storage/>`_)

For these profiles to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>`.

Queue: gpu (2 x NVIDIA Tesla k40m GPUs)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/aris-grnet/gpu_picongpu.profile.example
   :language: bash

Ascent (ORNL)
-------------

**System overview and user guide:** `link <https://docs.olcf.ornl.gov/systems/ascent_user_guide.html#system-overview/>`_

**Production directory:** usually ``$PROJWORK/$proj/`` (as on summit `link <https://www.olcf.ornl.gov/for-users/system-user-guides/summit/summit-user-guide/#file-systems>`_).

For this profile to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>` and install :ref:`openPMD-api and PNGwriter <install-dependencies>` manually or use pre-installed libraries in the shared project directory.

V100 GPUs (recommended)
^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/ascent-ornl/gpu_picongpu.profile.example
   :language: bash
   
DICC (UM)
---------

**System overview:** `link <https://www.dicc.um.edu.my/>`_

**User guide:** `link <https://confluence.dicc.um.edu.my/display/HPCDOCS/HPC+Documentation>`_

**Production directory:** usually ``/lustre/user/<username>`` (`link <https://confluence.dicc.um.edu.my/display/HPCDOCS/Managing+Storage>`_)

For these profiles to work, you need to download the :ref:`PIConGPU source code <install-dependencies-picongpu>`.

Queue: gpu (8 x NVIDIA Tesla k10 GPUs)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. literalinclude:: profiles/dicc-um/gpu_picongpu.profile.example
   :language: bash
