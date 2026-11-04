/* FUN_80162298
 * image   ovl_00a0344 (ovl), base 0x80161cf0
 * address 0x80162298  body 0x80162298..0x801623c3  size 300 B
 * body sha256 5e2c41dd648318fa2787fa8ce113478392c261cae63118c444e7c7d0166e18ae
 * provider record sha256 a010f9e2e946b5bdb847bedb98616c002522311e117ff675df62dca1aab7c4f6
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_80162298(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  int iVar4;
  
  sVar3 = *(short *)(param_1 + 500);
  *(short *)(param_1 + 500) = sVar3 + -1;
  if (sVar3 == 1) {
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
    *(undefined1 *)(param_1 + 0x2c5) = 0;
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
    if (*(char *)(*(int *)(param_1 + 0x250) + 0x2b4) == '\0') {
      iVar4 = -0x7ff1eed0;
    }
    else {
      iVar4 = _DAT_800e13ec;
    }
    sVar3 = *(short *)(*(int *)(param_1 + 0x250) + 0x66);
    *(short *)(param_1 + 0x1f6) = sVar3;
    if (*(byte *)(param_1 + 0x2b5) == 3) {
      uVar1 = func_0x80033604();
      *(ushort *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + 0x400 + (uVar1 & 1) * 0x800;
    }
    else {
      sVar2 = sVar3 + 0x400;
      if ((*(byte *)(param_1 + 0x2b5) & 2) == 0) {
        sVar2 = sVar3 + -0x400;
      }
      *(short *)(param_1 + 0x1f6) = sVar2;
    }
    sVar3 = func_0x80032e74(param_1,*(undefined4 *)(iVar4 + 0x28),*(undefined4 *)(iVar4 + 0x30),
                            0x100);
    *(short *)(param_1 + 0x1f6) = *(short *)(param_1 + 0x1f6) + sVar3;
  }
  func_0x80089d54(param_1,param_2,param_3,0x200);
  return;
}
