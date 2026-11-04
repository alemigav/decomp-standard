/* FUN_800713e0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800713e0  body 0x800713e0..0x8007148b  size 172 B
 * body sha256 5b462b3e8104675ebc28d6be16c44d0e1ce9d7f4f89a41f7e260569016a73f5e
 * provider record sha256 5617e564d9d1a86db8b8047d31b9c03a3d10a11384f592affec77a867d93d657
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_800713e0(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  uVar1 = *(ushort *)(iVar3 + 2);
  uVar2 = FUN_800717a0((int)((uint)*(ushort *)(iVar3 + 4) << 0x10) >> 0x18,
                       (int)(char)*(ushort *)(iVar3 + 4));
  local_18 = *(undefined2 *)(iVar3 + 8);
  local_16 = *(undefined2 *)(iVar3 + 10);
  local_14 = *(undefined2 *)(iVar3 + 0xc);
  FUN_800385a4((uint)(uVar1 >> 8) << 0x18 | (uVar1 & 0xff) << 0x10 | (uint)*(ushort *)(iVar3 + 6),
               (uint)*(ushort *)(iVar3 + 0xe) << 0x10 | (uint)*(byte *)(iVar3 + 1),uVar2,&local_18);
  *(int *)(param_1 + 0x1c) = iVar3 + 0x10;
  return 1;
}
