#!/bin/bash

namaFile=$1
namaC=$1".c"

gcc $namaC -o $namaFile
./$namaFile