#!/bin/bash

THIS_DIR=$(cd $(dirname $0) && pwd)

cmake ${THIS_DIR}/../.. -GXcode

