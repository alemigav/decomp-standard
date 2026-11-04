/* FUN_80167688
 * image   ovl_0090698 (ovl), base 0x80161cf0
 * address 0x80167688  body 0x80167688..0x8016782f  size 424 B
 * body sha256 f54c49eeb30cec972570b2768ac8312466fc52410e0ac54952f23204e892f590
 * provider record sha256 87dd9bb5611e3a5c0a5ba3ac63210508ec42f6f1405aa05da76c4227805a345e
 * callees 3 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80167688(int param_1,ushort param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  ushort uVar3;
  
  if (*(char *)(param_1 + 0x2d8) != '\x0e') {
    iVar1 = func_0x80036ed8(param_1,0,0x26,0);
    uVar2 = param_3 - 1;
    if ((iVar1 + (param_3 & 0xff) < 0x12) || (uVar2 = -iVar1 + 0x10, (-iVar1 + 0x11U & 0xff) != 0))
    {
      while (((uVar2 & 0xff) != 0xff && (iVar1 = func_0x80031ff0(0x26), iVar1 != 0))) {
        *(ushort *)(iVar1 + 0x1aa) = param_2 | *(short *)(param_1 + 0x1a8) != 0;
        *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x28);
        *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(param_1 + 0x2c);
        *(undefined4 *)(iVar1 + 0x30) = *(undefined4 *)(param_1 + 0x30);
        if (*(byte *)(param_1 + 0x2be) < 2) {
          uVar3 = func_0x80033604();
          *(ushort *)(iVar1 + 0x66) = (uVar3 & 0xff) << 4;
        }
        else {
          uVar3 = func_0x80033604();
          *(ushort *)(iVar1 + 0x66) =
               (ushort)*(byte *)(param_1 + 0x2cc) * 0x400 + -0x200 + (uVar3 & 0xff) * 4;
        }
        uVar2 = uVar2 - 1;
        *(undefined4 *)(iVar1 + 0x284) = 1;
        *(undefined4 *)(iVar1 + 0x120) = 0;
        *(undefined4 *)(iVar1 + 0x124) = 0;
        *(undefined4 *)(iVar1 + 0x128) = 0;
        *(undefined4 *)(iVar1 + 300) = 0x50005;
        *(undefined4 *)(iVar1 + 0x130) = 0;
        *(undefined4 *)(iVar1 + 0x134) = 0xffff0005;
        *(undefined4 *)(iVar1 + 0x138) = 0x50001;
        *(undefined4 *)(iVar1 + 0x13c) = 0;
      }
    }
  }
  return;
}
