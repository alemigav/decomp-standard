/* FUN_8004feac
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8004feac  body 0x8004feac..0x80050363  size 1208 B
 * body sha256 5526da907d164bfd70f090a85e0f5a2de2f285f206088be2404bb729f2412ed5
 * provider record sha256 90d2e7986521c3ebe182633ed8ea0374038c1d77dbdc5c935b93229057f35a1e
 * callees 10 direct (10 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8004feac(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  undefined2 *puVar8;
  int iVar9;
  uint *puVar10;
  
  iVar9 = 0;
  if ((DAT_800e1110 & 0x8000000) != 0) {
    return;
  }
  puVar10 = (uint *)0x0;
  DAT_800e110c = DAT_800e110c & 0xffffdfff;
  FUN_8004fc44();
  FUN_8004f9bc(&DAT_800e1130);
  puVar7 = &DAT_800e18f8;
  if (DAT_800e85f8 != &DAT_800e18f8) {
    puVar8 = &DAT_800e1aa0;
    do {
      if ((*puVar7 & 1) == 0) {
LAB_800500e4:
        *puVar8 = 0;
      }
      else {
        if (*(char *)(puVar8 + -0xd0) == '\x02') {
          FUN_80050964(puVar7);
        }
        FUN_80050eb8(puVar7);
        *(char *)(puVar8 + -3) = -(char)(*(int *)(puVar8 + -0xbe) / 0x708);
        if (((DAT_800e1134._1_1_ != '\x01') && (DAT_800e1134._1_1_ != '\n')) &&
           (DAT_800e1134._1_1_ != '\x02')) {
          *(undefined1 *)(puVar8 + 0x1c) = 0;
        }
        puVar6 = &DAT_800e13ec;
        if (DAT_800df93c != &DAT_800e13ec) {
          do {
            if ((*(uint *)*puVar6 & 1) != 0) {
              FUN_8004dd50((uint *)*puVar6,puVar7,0);
            }
            puVar6 = puVar6 + 1;
          } while (puVar6 != DAT_800df93c);
        }
        if ((*puVar7 & 0x200) == 0) {
          if (puVar7 == DAT_800e13b0) {
            FUN_8004ed84(&DAT_800e1130,puVar7);
          }
          else {
            iVar5 = FUN_8004dd50(&DAT_800e1130,puVar7,2);
            if (((iVar5 != 0) && (iVar9 = iVar9 + 1, DAT_800e12d2 == *(char *)(puVar8 + -3))) &&
               (iVar5 = FUN_8004e2cc(&DAT_800e1130,puVar7), iVar5 != 0)) {
              puVar10 = puVar7;
            }
          }
        }
        else {
          FUN_8004dd50(&DAT_800e1130,puVar7,1);
        }
        if (*(char *)(puVar8 + -0xd0) == '\x02') {
          if (*(char *)(puVar8 + -0xd2) == '\0') {
            uVar4 = FUN_80066c40(puVar7,0x4000,0x100);
            if ((uVar4 & 4) != 0) {
              FUN_80050e1c(puVar7);
              *(undefined1 *)(puVar8 + -0xd2) = 1;
              goto LAB_800500e4;
            }
            *puVar8 = 0;
          }
          else {
            *puVar8 = 0;
          }
        }
        else {
          *puVar8 = 0;
        }
      }
      puVar7 = puVar7 + 0xda;
      puVar8 = puVar8 + 0x1b4;
    } while (puVar7 != DAT_800e85f8);
  }
  if (((iVar9 == 1) && (puVar10 != (uint *)0x0)) &&
     (((*puVar10 & 2) == 0 && ((*puVar10 & 0x80) != 0)))) {
    cVar1 = *(char *)(puVar10 + 0x78);
    sVar2 = *(short *)((int)puVar10 + 0x2a);
    sVar3 = *(short *)((int)puVar10 + 0x32);
    *(byte *)(puVar10 + 0x78) = cVar1 + 1U;
    if (5 < (byte)(cVar1 + 1U)) {
      FUN_8004dd50(&DAT_800e1130,puVar10,1);
      uVar4 = FUN_80066c40(puVar10,0x4000,0);
      if ((uVar4 & 1) == 0) {
        puVar6 = &DAT_800e13ec;
        iVar9 = 0;
        if (DAT_800df93c != &DAT_800e13ec) {
          do {
            if ((*(uint *)*puVar6 & 1) != 0) {
              iVar5 = FUN_8004dd50((uint *)*puVar6,puVar10,1);
              iVar9 = iVar9 + iVar5;
            }
            puVar6 = puVar6 + 1;
          } while (puVar6 != DAT_800df93c);
        }
        puVar7 = &DAT_800e18f8;
        if (DAT_800e85f8 != &DAT_800e18f8) {
          do {
            if ((puVar10 != puVar7) && ((*puVar7 & 1) != 0)) {
              iVar5 = FUN_8004e100(puVar7,puVar10);
              iVar9 = iVar9 + iVar5;
            }
            puVar7 = puVar7 + 0xda;
          } while (puVar7 != DAT_800e85f8);
        }
        if (iVar9 == 0) {
          DAT_800e110c = DAT_800e110c | 0x2000;
          if (*(char *)(puVar10 + 0x78) != '\x06') {
            *(undefined1 *)(puVar10 + 0x78) = 7;
            goto LAB_800502ac;
          }
        }
        else {
          *(undefined1 *)(puVar10 + 0x78) = 0;
        }
      }
      else {
        *(undefined1 *)(puVar10 + 0x78) = 0;
      }
    }
    puVar10[10] = (int)sVar2;
    puVar10[0xc] = (int)sVar3;
    FUN_80050eb8(puVar10);
    FUN_80066c40(puVar10,0x4000,0);
  }
LAB_800502ac:
  puVar10 = &DAT_800e18f8;
  if (DAT_800e85f8 != &DAT_800e18f8) {
    puVar8 = &DAT_800e1aae;
    do {
      if ((*puVar10 & 1) != 0) {
        FUN_8004dd50(&DAT_800e1130,puVar10,0);
      }
      puVar10 = puVar10 + 0xda;
      puVar8[-1] = puVar8[-0x4a];
      *puVar8 = puVar8[-0x46];
      puVar8 = puVar8 + 0x1b4;
    } while (puVar10 != DAT_800e85f8);
  }
  if (DAT_800e13b0 == (uint *)0x0) {
    DAT_800e1320 = DAT_800e1320 & 63999;
  }
  return;
}
