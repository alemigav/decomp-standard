/* FUN_8007d154
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007d154  body 0x8007d154..0x8007d2ff  size 428 B
 * body sha256 d635c63cee1afd5ec4cd0cea741b519321534900fb6f204fa5d70e3dd39c7e9d
 * provider record sha256 0dbaf99f7e0fc34266f4772c0dc2faef0257484478ebaada87e6b84a84a7ee2f
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007d154(int param_1)

{
  short sVar1;
  short local_10 [4];
  
  local_10[0] = 0;
  local_10[1] = 3;
  local_10[2] = 6;
  if (*(char *)(param_1 + 6) == '\0') {
    sVar1 = local_10[*(char *)(param_1 + 0x1ed)];
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 500) = 0x3c;
    *(undefined2 *)(param_1 + 0x1f6) = 0x3c;
    *(int *)(param_1 + 0x1e8) = sVar1 * 0x1000000 + 0x700;
  }
  else if (*(char *)(param_1 + 6) != '\x01') goto LAB_8007d2a4;
  FUN_800334c8(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0);
  FUN_80089d54(param_1,*(undefined4 *)(param_1 + 0x21c),*(undefined4 *)(param_1 + 0x220),0x200);
  if ((**(uint **)(param_1 + 0x214) & 0x4000) != 0) {
    FUN_80077f30(0,((**(uint **)(param_1 + 0x214) & 0x2000) >> 0xd) * 3 + 4,param_1);
  }
  if ((*(ushort *)(param_1 + 0x2ba) < 0x5dc) && ((*(uint *)(param_1 + 0x1ac) & 1) != 0)) {
    sVar1 = *(short *)(param_1 + 500);
    *(short *)(param_1 + 500) = sVar1 + -1;
    if (sVar1 == 1) {
      *(undefined4 *)(param_1 + 4) = 0x1040000;
    }
  }
  else {
    *(undefined2 *)(param_1 + 500) = 0x3c;
  }
  if (*(uint *)(param_1 + 0x28c) < 0x5dc) {
    sVar1 = *(short *)(param_1 + 0x1f6);
    *(short *)(param_1 + 0x1f6) = sVar1 + -1;
    if (sVar1 == 1) {
      *(undefined4 *)(param_1 + 4) = 0x1040000;
    }
  }
  else {
    *(undefined2 *)(param_1 + 0x1f6) = 0x3c;
  }
LAB_8007d2a4:
  if ((int)*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e) + -500) {
    *(short *)(param_1 + 0x1e0) = *(short *)(param_1 + 0x1e0) - *(short *)(param_1 + 0x1e0) / 3;
  }
  FUN_80032b5c(param_1,0);
  return;
}
