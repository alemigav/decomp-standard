/* FUN_8007148c
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8007148c  body 0x8007148c..0x8007154b  size 192 B
 * body sha256 5b1770d1e48e064370ec9790b7bfc0665285dde685d2985a29fd5af32bc3e700
 * provider record sha256 58107680e6a7c26f926c4dc7852c736464f4fe4aa3094a3e3512cc971123c20b
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8007148c(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  uVar1 = *(ushort *)(iVar3 + 2);
  uVar2 = FUN_800717a0((int)((uint)*(ushort *)(iVar3 + 4) << 0x10) >> 0x18,
                       (int)(char)*(ushort *)(iVar3 + 4));
  local_20 = *(undefined2 *)(iVar3 + 8);
  local_1e = *(undefined2 *)(iVar3 + 10);
  local_1c = *(undefined2 *)(iVar3 + 0xc);
  local_18 = *(undefined2 *)(iVar3 + 0xe);
  local_16 = *(undefined2 *)(iVar3 + 0x10);
  local_14 = *(undefined2 *)(iVar3 + 0x12);
  FUN_80037c50((uint)(uVar1 >> 8) << 0x18 | (uVar1 & 0xff) << 0x10 | (uint)*(ushort *)(iVar3 + 6),
               (int)*(short *)(iVar3 + 0x14),uVar2,&local_20,&local_18);
  *(int *)(param_1 + 0x1c) = iVar3 + 0x16;
  return 1;
}
