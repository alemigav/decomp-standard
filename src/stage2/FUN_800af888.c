/* FUN_800af888
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af888  body 0x800af888..0x800af9cb  size 324 B
 * body sha256 287edb3b1b381f273d08a578d79ac1b432639ce06be253654c802d2f8f7fe8b7
 * provider record sha256 55afb4e229dbd380a78a2103f86adc9172b82c50ace209f9fdcb412303877ef6
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800af888(int param_1,uint *param_2)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  uint local_18 [2];
  
  if ((*param_2 & 0x3000000) == 0) {
    uVar1 = *(uint *)(param_1 + 0x24) & 0xffff7fff;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x24) | 0x8000;
  }
  *(uint *)(param_1 + 0x24) = uVar1;
  local_18[0] = (uint)*(ushort *)(param_2 + 1);
  if ((param_2[1] >> 8 & 1) == 0) {
    FUN_800ab514(local_18,param_1);
  }
  else {
    FUN_800ab504(local_18);
  }
  if (local_18[0] == 0) {
    *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) & 0xffffbfff;
    return 0;
  }
  *(uint *)(param_1 + 0x70) = local_18[0];
  *(uint *)(param_1 + 0x24) = *(uint *)(param_1 + 0x24) | 0x4000;
  uVar1 = *param_2;
  cVar3 = (char)(uVar1 >> 8);
  cVar2 = (char)(uVar1 >> 0x10);
  if (cVar3 < '\0') {
    if ((int)((uVar1 >> 0x10) << 0x18) < 0) {
      *(char *)(param_1 + 0x79) = -cVar2;
    }
    else {
      *(char *)(param_1 + 0x79) = cVar2;
    }
    *(char *)(param_1 + 0x78) = -cVar3;
    *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x70) >> 1;
    return 0;
  }
  if ((int)((uVar1 >> 0x10) << 0x18) < 0) {
    if (cVar3 == '\0') {
      *(char *)(param_1 + 0x79) = -cVar2;
      *(uint *)(param_1 + 0x6c) = *(uint *)(param_1 + 0x70) >> 1;
      goto LAB_800af9a0;
    }
    cVar3 = cVar3 + -1;
    *(char *)(param_1 + 0x79) = 'd' - cVar2;
  }
  else {
    *(char *)(param_1 + 0x79) = cVar2;
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
LAB_800af9a0:
  *(char *)(param_1 + 0x78) = cVar3;
  return 0;
}
