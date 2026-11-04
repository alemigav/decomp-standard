/* FUN_8017be6c
 * image   ovl_007e132 (ovl), base 0x8017b410
 * address 0x8017be6c  body 0x8017be6c..0x8017c167  size 764 B
 * body sha256 e1317b807dbbc33535c1bacc9b87920096cf1c64c686156ed0bc3761a7db84e3
 * provider record sha256 ec49ca84ead7425aaf2826f834f199a2818e60af5616846257245cab25b6fc43
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8017be6c(void)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 *puVar4;
  
  if ((((_DAT_800e10ec & 4) == 0) && ((DAT_800e9012 & 0xc) >> 3 != 0)) && (DAT_8017e758 != '\x0f'))
  {
    puVar4 = (undefined4 *)&DAT_800e13ec;
    if (_DAT_800df93c != (undefined4 *)&DAT_800e13ec) {
      do {
        puVar3 = (uint *)*puVar4;
        if ((*puVar3 & 1) != 0) {
          uVar2 = *puVar3 | 0x80000;
          if ((*(ushort *)((int)puVar3 + 0x1aa) & 0xc400) == 0) {
            if ((DAT_8017e734 & 1) == 0) {
              iVar1 = func_0x80040bb4((_DAT_800e1158 - puVar3[10]) * (_DAT_800e1158 - puVar3[10]) +
                                      (_DAT_800e1160 - puVar3[0xc]) * (_DAT_800e1160 - puVar3[0xc]))
              ;
              if (iVar1 < 0x1c21) {
LAB_8017c070:
                uVar2 = *puVar3 | 8;
              }
              else {
                if (*(char *)(puVar3 + 2) == ')') goto LAB_8017c07c;
                uVar2 = *puVar3 | 0x80000;
              }
            }
            else {
              iVar1 = func_0x80040bb4((_DAT_800e13ec[10] - puVar3[10]) *
                                      (_DAT_800e13ec[10] - puVar3[10]) +
                                      (_DAT_800e13ec[0xc] - puVar3[0xc]) *
                                      (_DAT_800e13ec[0xc] - puVar3[0xc]));
              if (iVar1 < 0x1c21) goto LAB_8017c070;
              if (*(char *)(puVar3 + 2) == ')') goto LAB_8017c07c;
              uVar2 = *puVar3 | 0x80000;
            }
          }
          *puVar3 = uVar2;
        }
LAB_8017c07c:
        puVar4 = puVar4 + 1;
      } while (puVar4 != _DAT_800df93c);
    }
    if ((DAT_8017e734 & 1) == 0) {
      *_DAT_800e1380 = *_DAT_800e1380 & 0xfff7ffff;
      *_DAT_800e1380 = *_DAT_800e1380 | 8;
    }
    else {
      *(uint *)_DAT_800e13ec[0x94] = *(uint *)_DAT_800e13ec[0x94] & 0xfff7ffff;
      *(uint *)_DAT_800e13ec[0x94] = *(uint *)_DAT_800e13ec[0x94] | 8;
      _DAT_800e1130 = _DAT_800e1130 | 0x80000;
      *_DAT_800e13ec = *_DAT_800e13ec & 0xfff7ffff;
    }
  }
  else {
    puVar4 = (undefined4 *)&DAT_800e13ec;
    if (_DAT_800df93c != (undefined4 *)&DAT_800e13ec) {
      do {
        uVar2 = *(uint *)*puVar4;
        if ((uVar2 & 1) != 0) {
          *(uint *)*puVar4 = uVar2 | 0x80000;
        }
        puVar4 = puVar4 + 1;
      } while (puVar4 != _DAT_800df93c);
    }
    _DAT_800e1130 = _DAT_800e1130 | 0x80000;
  }
  return;
}
