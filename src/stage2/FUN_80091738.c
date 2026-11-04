/* FUN_80091738
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80091738  body 0x80091738..0x80091a5f  size 80 B
 * body sha256 6cbf33be37a083ada2870fd94012d219f08f49eca2d1d37052d39300d6de8744
 * provider record sha256 d80386b1bcf82977af5d4ed4dd012a9ac04f638f585fe38f78e9c89b6b92132f
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80091738(undefined4 param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(param_1) {
  case 0:
    if (((param_2 == 0x11) || (param_2 == 0x17)) || ((param_2 == 0x12 && (DAT_800e12d2 == 3)))) {
      uVar2 = 4;
    }
    else {
      uVar2 = 0;
      if ((((3 < param_2) && (uVar2 = 1, 7 < param_2)) && (uVar2 = 3, 0x15 < param_2)) &&
         ((uVar2 = 0, param_2 == 0x16 && (uVar2 = 3, DAT_800e12d2 != 4)))) {
        uVar2 = 2;
      }
    }
    break;
  case 1:
    if (param_2 == 0x1b) {
      uVar2 = 3;
    }
    else {
      uVar2 = 5;
      if (param_2 < 0x11) {
        uVar2 = 2;
      }
    }
    break;
  case 2:
    uVar2 = 5;
    if ((1 < param_2) && (uVar2 = 6, param_2 == 8)) {
      uVar2 = 5;
    }
    break;
  case 3:
    if (((((param_2 == 0) && (3 < DAT_800e12d2)) || ((param_2 == 1 && (3 < DAT_800e12d2)))) ||
        (((param_2 == 3 && (3 < DAT_800e12d2)) || (param_2 == 0xb)))) ||
       ((param_2 == 2 || (uVar2 = 8, param_2 == 9)))) {
      uVar2 = 7;
    }
    break;
  case 4:
    uVar2 = 9;
    if (2 < param_2) {
      if (param_2 == 8) {
        uVar2 = 9;
      }
      else if (((DAT_800e110c & 0x40000000) == 0) || (param_2 != 3)) {
        if (param_2 == 5) {
          if ((DAT_800e110c & 0x40000000) == 0) {
            iVar1 = FUN_800837ac(&DAT_800e8ce0,0xbe);
            if (iVar1 != 0) {
              return 0x10;
            }
          }
          else {
            iVar1 = FUN_800837ac(&DAT_800e8ce0,0xbe);
            if (iVar1 != 0) {
              return 0xd;
            }
          }
          iVar1 = FUN_800837ac(&DAT_800e8ce0,99);
          if (iVar1 != 0) {
            return 0xc;
          }
        }
        uVar2 = 10;
        if ((5 < param_2) && (uVar2 = 0xc, param_2 != 9)) {
          uVar2 = 0xb;
        }
      }
      else {
        iVar1 = FUN_800837ac(&DAT_800e8ce0,0x62);
        uVar2 = 10;
        if (iVar1 == 0) {
          uVar2 = 0xb;
        }
      }
    }
    break;
  case 5:
    if (param_2 == 1) {
      uVar2 = 0xd;
      if (DAT_800e8cae != 0x602) {
        uVar2 = 0x10;
      }
    }
    else if ((param_2 != 3) || (uVar2 = 0xe, 2 < DAT_800e12d2)) {
      if ((param_2 != 0xe) || (DAT_8012f528 != '\x01')) {
        if (param_2 < 5) {
          return 0xd;
        }
        if (param_2 == 5) {
          return 0xf;
        }
        if (param_2 < 0x12) {
          return 0x10;
        }
      }
      uVar2 = 0x11;
    }
    break;
  case 6:
    iVar1 = FUN_800837ac(&DAT_800e8ce0,0x89);
    uVar2 = 0x13;
    if (iVar1 == 0) {
      uVar2 = 0x12;
    }
    break;
  default:
    uVar2 = 0;
  }
  return uVar2;
}
