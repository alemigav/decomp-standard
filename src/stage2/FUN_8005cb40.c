/* FUN_8005cb40
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8005cb40  body 0x8005cb40..0x8005cf5f  size 1056 B
 * body sha256 105cebbd212733d6ad57d79d300183511fe7084abe73c603221e29579ba5e33e
 * provider record sha256 2fb264e3b8b4dcecd2cae3f3c9c3bbbae451f0633a0d64a8d3ee234749932789
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8005cb40(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  bVar1 = *(byte *)(param_1 + 7);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 == 2) {
        *(undefined2 *)(param_1 + 6) = 0x100;
        return;
      }
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000700;
    *(undefined1 *)(param_1 + 7) = 1;
    *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x4000;
    if ((*(ushort *)(param_1 + 0x1aa) & 0xfff) == 1) {
      if ((_DAT_800e8ca8 == 0x3000a) || (_DAT_800e8ca8 == 0x60004)) {
        uVar4 = 30000;
      }
      else {
        uVar4 = 5000;
      }
    }
    else {
      uVar4 = 0;
    }
    FUN_8005bc04(param_1,uVar4);
    *(undefined1 *)(param_1 + 0x207) = 0;
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 0x12;
  }
  if (*(short *)(param_1 + 0x1a8) != 0) {
    if (((*(short *)(param_1 + 0x1a8) < *(short *)(param_1 + 0x25e)) &&
        (*(byte *)(param_1 + 0x1e9) < 6)) && ((*(byte *)(param_1 + 0x1e9) & 1) != 0)) {
      FUN_8005c3e8(param_1);
    }
    iVar7 = *(int *)(param_1 + 0x234);
    local_20 = 0;
    local_1e = 300;
    local_1c = 0;
    if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(iVar7 + 0x1078) + 300) {
      uVar2 = FUN_80033604();
      FUN_80037780((uVar2 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)(param_1 + 0x66),
                   iVar7 + 0x1060,&local_20);
    }
    iVar7 = *(int *)(param_1 + 0x234);
    if ((int)*(short *)(param_1 + 0x1a8) < *(int *)(iVar7 + 0x14e0) + 300) {
      uVar2 = FUN_80033604();
      FUN_80037780((uVar2 & 0xff) * 4 + 0x60c | 0x1a000000,(int)*(short *)(param_1 + 0x66),
                   iVar7 + 0x14c8,&local_20);
    }
  }
  if (((DAT_800e8b58 & 1) == 0) && (iVar7 = *(int *)(param_1 + 0x250), iVar7 != param_1)) {
    if ((*(ushort *)(param_1 + 0x1aa) & 0xfff) == 0xd) {
      uVar4 = *(undefined4 *)(iVar7 + 0x120);
      uVar5 = *(undefined4 *)(iVar7 + 0x128);
      uVar6 = 0x120;
    }
    else {
      uVar4 = *(undefined4 *)(iVar7 + 0x120);
      uVar5 = *(undefined4 *)(iVar7 + 0x128);
      uVar6 = 0xd8;
    }
    FUN_80032dbc(param_1,uVar4,uVar5,uVar6);
  }
  if (((DAT_800df918 & 0x20) != 0) && (*(char *)(param_1 + 0x207) == '\0')) {
    FUN_8005bc04(param_1,3000);
    *(undefined1 *)(param_1 + 0x207) = 1;
  }
  cVar3 = DAT_800df8c0;
  if (((param_4 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x20;
  }
  if (((param_4 & 2) != 0) || ('\x19' < cVar3)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x20;
  }
  cVar3 = FUN_80089d54(param_1,param_2,param_3,0x200);
  uVar2 = *(ushort *)(param_1 + 0x1aa) & 0xfff;
  *(char *)(param_1 + 7) = *(char *)(param_1 + 7) + cVar3;
  if ((uVar2 != 0xe) && (uVar2 != 0x11)) {
    if ((((&DAT_80110e24)[(uVar2 - 1) * 3] & 0x7f) < *(byte *)(param_1 + 0x1e9)) &&
       (((param_4 & 0x20) != 0 || (DAT_800df8c1 < -0x19)))) {
      *(undefined2 *)(param_1 + 6) = 0x100;
      *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x2000;
    }
    else if ((((&DAT_80110e25)[((*(ushort *)(param_1 + 0x1aa) & 0xfff) - 1) * 3] & 0x7f) <
              *(byte *)(param_1 + 0x1e9)) && (((param_4 & 0x10) != 0 || ('\x19' < DAT_800df8c1)))) {
      *(undefined2 *)(param_1 + 6) = 0x100;
      *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x8000;
    }
  }
  return;
}
