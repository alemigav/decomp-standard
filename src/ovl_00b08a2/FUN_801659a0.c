/* FUN_801659a0
 * image   ovl_00b08a2 (ovl), base 0x80161cf0
 * address 0x801659a0  body 0x801659a0..0x80165ad7  size 312 B
 * body sha256 609b5b7964162aa527806cb908377e542eb671fcf36b3b39be0e29e7fa2bdf81
 * provider record sha256 23ef19e1193cf6012f4882f00bf2bd970139466e2ed6bfca17f86c5ac4eebdb6
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801659a0(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  char cVar2;
  uint *puVar3;
  uint uVar4;
  
  bVar1 = *(byte *)((int)param_1 + 6);
  uVar4 = param_1[0x8d];
  if (bVar1 == 1) {
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x40);
    *(char *)((int)param_1 + 6) = *(char *)((int)param_1 + 6) + cVar2;
  }
  else if (bVar1 < 2) {
    if (bVar1 == 0) {
      param_1[0x7a] = 0xd000000;
      *(undefined2 *)(param_1 + 0x1a) = 0;
      *(undefined2 *)((int)param_1 + 0x66) = 0;
      *(undefined2 *)(param_1 + 0x19) = 0;
      *param_1 = *param_1 | 2;
      puVar3 = *(uint **)((*(byte *)(param_1 + 0xad) + 7) * 4 + -0x7ff1ec18);
      *puVar3 = *puVar3 | 2;
      *(undefined2 *)(uVar4 + 0x124) = 0x1000;
      if ((param_1[0x9c] & 0x10000) != 0) {
        *(undefined1 *)((int)param_1 + 6) = 1;
      }
    }
  }
  else if (bVar1 == 2) {
    param_1[1] = 0x1080000;
    *(undefined1 *)((int)param_1 + 0x2b5) = 0;
    *(undefined2 *)(uVar4 + 0x124) = 0;
    *param_1 = *param_1 & 0xfffffffd;
    puVar3 = *(uint **)((*(byte *)(param_1 + 0xad) + 7) * 4 + -0x7ff1ec18);
    *puVar3 = *puVar3 & 0xfffffffd;
  }
  return;
}
