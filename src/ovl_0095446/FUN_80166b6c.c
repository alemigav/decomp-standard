/* FUN_80166b6c
 * image   ovl_0095446 (ovl), base 0x80161cf0
 * address 0x80166b6c  body 0x80166b6c..0x80166e57  size 748 B
 * body sha256 8c3fd5129aec1cd5119f09960e3582018993d05928b5a57ae2c3e9a4e71667ed
 * provider record sha256 8e252c9a5b91b020a645d9afbcf4649bff01d3a6dd754426e14e3458800eaeaa
 * callees 7 direct (7 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166b6c(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  
  bVar3 = *(byte *)(param_1 + 6);
  *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) | 0x82;
  if (bVar3 == 1) {
LAB_80166c24:
    if ((*(char *)(param_1 + 5) == '\x0e') && ((*(byte *)(param_1 + 0x1e9) & 3) == 0)) {
      FUN_8016524c(param_1,0);
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x200);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 0x1e8) = 0xa003f00;
      iVar1 = *(int *)(param_1 + 0x234);
      *(undefined1 *)(param_1 + 6) = 2;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
      uVar2 = func_0x80033604();
      func_0x80037780((uVar2 & 0xff) * 4 + 0x17d0 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                      iVar1 + 0xd70,0);
      iVar1 = *(int *)(param_1 + 0x234);
      uVar2 = func_0x80033604();
      func_0x80037780((uVar2 & 0xff) * 4 + 0x1fa0 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                      iVar1 + 0x1350,0);
      iVar1 = *(int *)(param_1 + 0x234);
      uVar2 = func_0x80033604();
      func_0x80037780((uVar2 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                      iVar1 + 0x4a0,0);
      iVar1 = *(int *)(param_1 + 0x234);
      uVar2 = func_0x80033604();
      func_0x80037780((uVar2 & 0xff) * 4 + 0x1000 | 0x40f0000,(int)*(short *)(param_1 + 0x66),
                      iVar1 + 0x1b0,0);
      if (*(char *)(param_1 + 5) == '\x0e') {
        FUN_8016524c(param_1,1);
      }
    }
  }
  else {
    if (bVar3 < 2) {
      if (bVar3 != 0) goto LAB_80166db4;
      *(undefined1 *)(param_1 + 6) = 1;
      *(undefined4 *)(param_1 + 0x1e8) = 0x6000700;
      *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfd;
      *(short *)(param_1 + 0x66) =
           *(short *)(param_1 + 0x66) + *(short *)(*(int *)(param_1 + 0x234) + 0x5a);
      *(undefined2 *)(*(int *)(param_1 + 0x234) + 0x5a) = 0;
      if (*(char *)(param_1 + 5) == '\x11') {
        FUN_80164e20(param_1);
      }
      *(ushort *)(param_1 + 0x2ba) = *(ushort *)(param_1 + 0x2ba) | 0x1000;
      goto LAB_80166c24;
    }
    if (bVar3 != 2) goto LAB_80166db4;
    func_0x800334c8(param_1,param_2,param_3,0);
    iVar1 = func_0x80089d54(param_1,param_2,param_3,0x40);
    if (iVar1 != 0) {
      *(undefined4 *)(param_1 + 4) = 0x1010000;
      *(byte *)(param_1 + 0x2be) = *(byte *)(param_1 + 0x2be) & 0x7f;
    }
  }
  func_0x80032b5c(param_1,0);
LAB_80166db4:
  if ((*(byte *)(param_1 + 0x1e9) & 3) == 0) {
    bVar3 = func_0x80033604();
    DAT_80167fca = '\x03' - bVar3 % 6;
    bVar3 = func_0x80033604();
    DAT_80167fcb = '\x0f' - bVar3 % 0x1e;
  }
  return;
}
