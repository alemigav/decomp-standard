/* FUN_8000c0d0
 * image   boot (boot), base 0x80000480
 * address 0x8000c0d0  body 0x8000c0d0..0x8000c463  size 676 B
 * body sha256 43b2ab9c2a0be45f62efef8bb26eed578efec5fd60da66538fcdf56cf8ef2c36
 * provider record sha256 ffc641e0796905ad72bd3f6d0cd6d48acfae182f0d285423e9fea50ce74ccb33
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Removing unreachable block (ram,0x8000c430) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8000c0d0(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  ushort *local_30;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [4];
  uint local_24;
  
  local_30 = (ushort *)0x0;
  do {
    while( true ) {
      osRecvMesg(*(undefined4 *)(param_1 + 8),&local_30,1);
      iVar3 = *(int *)(local_30 + 10);
      if (((iVar3 == 0) || (*(char *)(iVar3 + 4) != '\x02')) || (1 < *(uint *)(iVar3 + 0x14)))
      break;
      *(undefined4 *)(iVar3 + 0x1c) = 0xffffffff;
      iVar2 = iVar3 + (uint)*(ushort *)(iVar3 + 0x1a) * 0x24;
      if (*(short *)(iVar3 + 0x18) != 3) {
        *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) - *(int *)(iVar2 + 0x38);
      }
      bVar1 = false;
      if (*(short *)(iVar3 + 0x18) == 2) {
        bVar1 = *(int *)(*(int *)(local_30 + 10) + 0x14) == 0;
      }
      osRecvMesg(*(undefined4 *)(param_1 + 0x10),auStack_2c,1);
      FUN_8000cb10(0x100401);
      FUN_8000c630(*(undefined4 *)(local_30 + 10),0x5000510,*(uint *)(iVar3 + 0x24) | 0x80000000);
      do {
        osRecvMesg(*(undefined4 *)(param_1 + 0xc),auStack_28,1);
        iVar3 = *(int *)(local_30 + 10);
        piVar4 = (int *)(iVar3 + (uint)*(ushort *)(iVar3 + 0x1a) * 0x24 + 0x2c);
        if (*piVar4 == 0x1d) {
          FUN_8000c630(iVar3,0x5000510,*(uint *)(iVar3 + 0x24) | 0x10000000);
          FUN_8000c630(*(undefined4 *)(local_30 + 10),0x5000510,*(undefined4 *)(iVar3 + 0x24));
          FUN_8000c490(*(undefined4 *)(local_30 + 10),0x5000508,&local_24);
          if ((local_24 & 0x2000000) != 0) {
            FUN_8000c630(*(undefined4 *)(local_30 + 10),0x5000510,
                         *(uint *)(iVar3 + 0x24) | 0x1000000);
          }
          *piVar4 = 4;
          _DAT_a4600010 = 2;
          FUN_8000cd00(0x100c01);
        }
        osSendMesg(*(undefined4 *)(local_30 + 2),local_30,0);
      } while ((bVar1) && (bVar1 = false, *(int *)(*(int *)(local_30 + 10) + 0x2c) == 0));
      osSendMesg(*(undefined4 *)(param_1 + 0x10),0,0);
      if (*(short *)(*(int *)(local_30 + 10) + 0x1a) == 1) {
        FUN_80011390();
      }
    }
  } while (6 < *local_30 - 10);
                    /* WARNING: Could not emulate address calculation at 0x8000c328 */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)((*local_30 - 10) * 4 + -0x7ffee490))();
  return;
}
