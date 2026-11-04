/* FUN_800a7b64
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a7b64  body 0x800a7b64..0x800a7e2f  size 716 B
 * body sha256 bbb6f0b5699da42f75da3bd9849c92638d61706987c0cde92035001067fd8c42
 * provider record sha256 abcb57739572c5cc6e5d1e17f5e03e8d79a92d32a0da51d4cd6072200d38ab62
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a7b64(uint param_1,ushort param_2,uint param_3,undefined1 param_4,undefined4 param_5)

{
  char cVar2;
  int iVar1;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  uint local_20 [2];
  
  if (param_2 == 0) {
    param_2 = 1;
  }
  uVar6 = (uint)param_2;
  local_20[0] = uVar6;
  FUN_800ab504(local_20);
  switch(param_3 & 0xff) {
  case 0xfa:
    cVar2 = '\x02';
    break;
  case 0xfb:
    cVar2 = '\x03';
    break;
  case 0xfc:
    uVar6 = 0;
    iVar1 = (param_1 & 0xff) * 0x10000;
    uVar5 = (uint)param_2;
    piVar4 = (int *)&DAT_80147aa0;
    do {
      if (*(byte *)(piVar4 + 5) - 2 < 2) {
        piVar4[1] = iVar1;
        iVar3 = iVar1 - *piVar4;
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        if ((uVar5 == 0xffffffff) && (iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        piVar4[3] = local_20[0];
        piVar4[4] = -1;
        piVar4[2] = iVar3 / (int)uVar5;
      }
      uVar6 = uVar6 + 1;
      piVar4 = piVar4 + 10;
    } while (uVar6 < 0x20);
    return;
  case 0xfd:
    cVar2 = '\0';
    break;
  case 0xfe:
    cVar2 = '\x01';
    break;
  case 0xff:
    uVar6 = 0;
    iVar1 = (param_1 & 0xff) * 0x10000;
    uVar5 = (uint)param_2;
    piVar4 = (int *)&DAT_80147aa0;
    do {
      if (*(byte *)(piVar4 + 5) < 2) {
        piVar4[1] = iVar1;
        iVar3 = iVar1 - *piVar4;
        if (uVar5 == 0) {
          trap(0x1c00);
        }
        if ((uVar5 == 0xffffffff) && (iVar3 == -0x80000000)) {
          trap(0x1800);
        }
        piVar4[3] = local_20[0];
        piVar4[4] = -1;
        piVar4[2] = iVar3 / (int)uVar5;
      }
      uVar6 = uVar6 + 1;
      piVar4 = piVar4 + 10;
    } while (uVar6 < 0x20);
    return;
  default:
    iVar3 = (param_3 & 0xff) * 0x28;
    iVar1 = (param_1 & 0xff) * 0x10000;
    *(int *)(&DAT_80147aa4 + iVar3) = iVar1;
    iVar1 = iVar1 - *(int *)(&DAT_80147aa0 + iVar3);
    if (uVar6 == 0) {
      trap(0x1c00);
    }
    if ((uVar6 == 0xffffffff) && (iVar1 == -0x80000000)) {
      trap(0x1800);
    }
    (&DAT_80147ab5)[iVar3] = param_4;
    *(uint *)(&DAT_80147aac + iVar3) = local_20[0];
    *(undefined4 *)(&DAT_80147ab0 + iVar3) = param_5;
    *(int *)(&DAT_80147aa8 + iVar3) = iVar1 / (int)uVar6;
    return;
  }
  uVar6 = 0;
  iVar1 = (param_1 & 0xff) * 0x10000;
  uVar5 = (uint)param_2;
  piVar4 = (int *)&DAT_80147aa0;
  do {
    uVar6 = uVar6 + 1;
    if (*(char *)(piVar4 + 5) == cVar2) {
      piVar4[1] = iVar1;
      iVar3 = iVar1 - *piVar4;
      if (uVar5 == 0) {
        trap(0x1c00);
      }
      if ((uVar5 == 0xffffffff) && (iVar3 == -0x80000000)) {
        trap(0x1800);
      }
      piVar4[3] = local_20[0];
      piVar4[4] = -1;
      piVar4[2] = iVar3 / (int)uVar5;
    }
    piVar4 = piVar4 + 10;
  } while (uVar6 < 0x20);
  return;
}
