/* FUN_8007ddc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007ddc0  body 0x8007ddc0..0x8007de77  size 184 B
 * body sha256 6750c98b32dab6a2a4301d03b19fa1043329fd8e6e25d629123ec38882666854
 * provider record sha256 ffb4175aea0dc2fbfc07236285a414622bb10c09e44fbc0fa34d681609504b7e
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8007ddc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  short local_18 [8];
  
  local_18[0] = 0;
  local_18[1] = 0xf;
  local_18[2] = 0xb;
  local_18[3] = 0;
  local_18[4] = 0xd;
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    sVar1 = local_18[*(ushort *)(param_1 + 0x1f0) >> 0xd];
    *(undefined2 *)(param_1 + 500) = 0x1e;
    *(int *)(param_1 + 0x1e8) = sVar1 * 0x1000000 + 0x700;
  }
  FUN_80089d54(param_1,param_2,param_3,0x200);
  sVar1 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar1 + -1;
  if (sVar1 == 1) {
    *(undefined2 *)(param_1 + 6) = 0x300;
  }
  return;
}
