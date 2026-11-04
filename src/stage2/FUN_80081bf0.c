/* FUN_80081bf0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80081bf0  body 0x80081bf0..0x80081d1b  size 300 B
 * body sha256 1098d8eaef5e1fefef35ab39c8f3ec944d64371ffc3fcf850e8558c2f66e069e
 * provider record sha256 df6625949329f74686c2173e5407f1f9f4fa588294a1e12da04d1309cfa13bd4
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80081bf0(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  short sVar3;
  
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined1 *)(param_1 + 0x1ea) = 7;
    if ((*(ushort *)(param_1 + 0x268) & 0x40) != 0) {
      *(undefined1 *)(param_1 + 0x1ea) = 0;
    }
  }
  iVar2 = FUN_80089d54(param_1,param_2,param_3,
                       (uint)(*(byte *)(param_1 + 0x269) >> 7) << 0x10 | 0x200);
  if (iVar2 == 0) {
    if (((*(ushort *)(param_1 + 0x268) & 8) != 0) &&
       (iVar2 = FUN_80089d54(param_1,param_2,param_3,
                             (uint)((*(ushort *)(param_1 + 0x268) & 0x80) != 0) << 0x10 | 0x200),
       iVar2 != 0)) {
      *(undefined1 *)(param_1 + 6) = 2;
      if ((*(ushort *)(param_1 + 0x268) & 4) != 0) {
        *(undefined1 *)(param_1 + 6) = 1;
      }
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x272);
    }
    sVar3 = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x270);
  }
  else {
    *(undefined1 *)(param_1 + 6) = 2;
    if ((*(ushort *)(param_1 + 0x268) & 4) != 0) {
      *(undefined1 *)(param_1 + 6) = 1;
    }
    sVar3 = *(short *)(param_1 + 0x66) + *(short *)(param_1 + 0x272);
  }
  *(short *)(param_1 + 0x66) = sVar3;
  return;
}
