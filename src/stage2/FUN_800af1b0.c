/* FUN_800af1b0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800af1b0  body 0x800af1b0..0x800af34b  size 412 B
 * body sha256 cba7cbecd9fe0ab377cc9ad0a59507d5614560315a7a4ab56a867fc05afaf227
 * provider record sha256 8477bb1e1c8d1db5664082be260ce8e2ecdf95bba45e459495067eb72b9f0206
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
bool FUN_800af1b0(int param_1,uint *param_2)

{
  uint uVar1;
  char cVar3;
  int iVar2;
  uint local_18 [2];
  
  local_18[0] = (uint)*(ushort *)(param_2 + 1);
  if (local_18[0] == 0) {
    return false;
  }
  if ((*param_2 >> 8 & 1) == 0) {
    uVar1 = *(uint *)(param_1 + 0x24) & 0xfffffffb;
  }
  else {
    if ((*(uint *)(param_1 + 0x24) & 8) != 0) {
      return false;
    }
    uVar1 = *(uint *)(param_1 + 0x24) | 4;
  }
  *(uint *)(param_1 + 0x24) = uVar1;
  if ((*param_2 & 0x1000000) == 0) {
    uVar1 = *(uint *)(param_1 + 0x24) & 0xffefffff;
  }
  else {
    if (((*(uint *)(param_1 + 0x24) & 0x20) == 0) &&
       (cVar3 = FUN_800a5890(*(undefined1 *)(param_1 + 99)), cVar3 == '\0')) {
      return false;
    }
    uVar1 = *(uint *)(param_1 + 0x24) | 0x100000;
  }
  *(uint *)(param_1 + 0x24) = uVar1;
  if ((*param_2 & 0x10000) != 0) {
    uVar1 = FUN_800ab3cc();
    if (local_18[0] == 0) {
      trap(0x1c00);
    }
    local_18[0] = (uVar1 & 0xffff) % local_18[0];
  }
  iVar2 = -1;
  if (local_18[0] != 0xffff) {
    if ((param_2[1] >> 8 & 1) == 0) {
      FUN_800ab514(local_18,param_1);
      local_18[0] = *(int *)(param_1 + 0xa0) + local_18[0];
      *(uint *)(param_1 + 0x9c) = local_18[0];
      if (local_18[0] <= *(uint *)(param_1 + 0xa4)) {
        *(uint *)(param_1 + 0xa0) = local_18[0];
        *(undefined4 *)(param_1 + 0x9c) = 0;
      }
      goto LAB_800af328;
    }
    FUN_800ab504(local_18);
    iVar2 = *(int *)(param_1 + 0xa4) + local_18[0];
  }
  *(int *)(param_1 + 0x9c) = iVar2;
LAB_800af328:
  return *(int *)(param_1 + 0x9c) != 0;
}
