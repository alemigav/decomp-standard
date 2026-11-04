/* FUN_80058858
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80058858  body 0x80058858..0x8005889b  size 68 B
 * body sha256 2cf3f1ce0d800c7e55d9e9cd4f3ed487b6280d90bdf616d1296a915c2fc89933
 * provider record sha256 3245729f364a540ab693e3857ff2ed6ff6e76c7f1ccd722e5452280cf56dd463
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80058858(uint *param_1)

{
  char cVar1;
  short sVar2;
  undefined2 uVar4;
  int iVar3;
  char cVar5;
  uint *puVar6;
  int *piVar7;
  
  switch(*(undefined1 *)((int)param_1 + 7)) {
  case 0:
    *(undefined1 *)((int)param_1 + 7) = 1;
    param_1[0x7a] = 0x7000700;
    *param_1 = *param_1 | 4;
  case 1:
    cVar5 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar5;
    cVar5 = '\x0e';
    if (*(char *)(param_1 + 2) == '\x0f') {
      cVar1 = *(char *)((int)param_1 + 0x1e9);
      cVar5 = '\x1a';
    }
    else {
      cVar1 = *(char *)((int)param_1 + 0x1e9);
    }
    if (cVar1 == cVar5) {
      *(undefined1 *)((int)param_1 + 7) = 2;
    }
    break;
  case 2:
    *(undefined1 *)((int)param_1 + 7) = 3;
    param_1[0x7a] = 0x8000000;
    *(undefined2 *)(param_1 + 0x78) = 1000;
    *(undefined2 *)(param_1 + 0x7d) = 0;
    *(undefined2 *)(param_1 + 0x7d) = 5;
    param_1[0xb] = param_1[0xb] + 0x226;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    if (*(char *)(param_1 + 2) == '\x0f') {
      *(undefined2 *)(param_1 + 0x78) = 600;
      *(undefined2 *)(param_1 + 0x7d) = 3;
      param_1[0xb] = param_1[0xb] - 400;
    }
    *(undefined2 *)(param_1 + 0x79) = 0;
    FUN_80032b5c(param_1,0);
    *(undefined1 *)((int)param_1 + 0x207) = 0;
    *(char *)((int)param_1 + 0x1a2) = *(char *)((int)param_1 + 0x1a2) + -1;
    *(undefined2 *)(param_1 + 0x6d) = *(undefined2 *)((int)param_1 + 0x2a);
    *(undefined2 *)((int)param_1 + 0x1b6) = *(undefined2 *)((int)param_1 + 0x32);
  case 3:
    sVar2 = *(short *)(param_1 + 0x7d);
    *(short *)(param_1 + 0x7d) = sVar2 + 1;
    param_1[0xb] = param_1[0xb] + sVar2 * 0x1e;
    uVar4 = FUN_80069f1c(param_1 + 10,*(undefined2 *)((int)param_1 + 0x136),0x8000,0);
    *(undefined2 *)((int)param_1 + 0x25e) = uVar4;
    *(char *)((int)param_1 + 0x1a2) = -(char)((int)param_1[0xb] / 0x708);
    puVar6 = &DAT_800e18f8;
    if (&DAT_800e18f8 < DAT_800e85f8) {
      piVar7 = &DAT_800e1a1c;
      do {
        if (((*puVar6 & 1) != 0) && ((*puVar6 & 2) == 0)) {
          FUN_80050eb8(puVar6);
          iVar3 = FUN_8004f774(param_1 + 10,puVar6,*(undefined2 *)((int)param_1 + 0x136),0);
          if ((iVar3 != 0) &&
             ((int)*(short *)((int)param_1 + 0x25e) ==
              *piVar7 - (uint)*(ushort *)((int)piVar7 + 0x16))) {
            param_1[0xa0] = (uint)puVar6;
            break;
          }
        }
        puVar6 = puVar6 + 0xda;
        piVar7 = piVar7 + 0xda;
      } while (puVar6 < DAT_800e85f8);
    }
    if (param_1[0xa0] != 0) {
      FUN_8004f634(&DAT_800e1130,param_1[0xa0],(uint)*(byte *)((int)param_1 + 9) << 8,0x30);
    }
    FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    if ((*(short *)(param_1 + 0x6a) < *(short *)((int)param_1 + 0x25e)) &&
       (*(char *)((int)param_1 + 0x207) == '\0')) {
      *(undefined1 *)((int)param_1 + 0x207) = 0x85;
    }
    if ((*(byte *)((int)param_1 + 0x207) & 0x7f) != 0) {
      *(byte *)((int)param_1 + 0x207) = *(byte *)((int)param_1 + 0x207) - 1;
      FUN_8005c3e8(param_1);
    }
    if (*(short *)((int)param_1 + 0x25e) + -300 < (int)param_1[0xb]) {
      *(undefined1 *)((int)param_1 + 7) = 4;
      FUN_80052bd0(1,0);
      FUN_80052c6c(6,0x96,0);
    }
    break;
  case 4:
    *(undefined1 *)((int)param_1 + 7) = 5;
    *(undefined1 *)(param_1 + 0x7a) = 9;
    if (4 < (*(byte *)((int)param_1 + 6) & 0xc)) {
      *(undefined1 *)(param_1 + 0x7a) = 7;
    }
    *(undefined1 *)((int)param_1 + 0x1e9) = 4;
    *(undefined1 *)((int)param_1 + 0x1ea) = 7;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) & 0x7f;
    param_1[0xb] = (int)*(short *)((int)param_1 + 0x25e);
    *param_1 = *param_1 & 0xfffffffb;
    FUN_80077f30(1,4,param_1);
    DAT_800e112a = DAT_800e112a | 4;
  case 5:
    if (*(char *)((int)param_1 + 0x1e9) == '\x06') {
      FUN_80077f30(1,7,param_1);
    }
    *(char *)((int)param_1 + 0x1a2) = -(char)((int)param_1[0xb] / 0x708);
    if (param_1[0xa0] != 0) {
      FUN_8004f634(&DAT_800e1130,param_1[0xa0],(uint)*(byte *)((int)param_1 + 9) << 8,0x30);
    }
    cVar5 = FUN_80089d54(param_1,param_1[0x8b],param_1[0x8c],0x200);
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar5;
    break;
  case 6:
    DAT_800e110c = DAT_800e110c & 0xffffffbf;
    if (param_1[0xa0] != 0) {
      FUN_8004f634(&DAT_800e1130,param_1[0xa0],(uint)*(byte *)((int)param_1 + 9) << 8,1000);
    }
    *(undefined1 *)((int)param_1 + 5) = 0;
    *(undefined1 *)((int)param_1 + 6) = 0;
    *(undefined1 *)((int)param_1 + 7) = 0;
  }
  return;
}
