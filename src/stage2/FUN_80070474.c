/* FUN_80070474
 * image   stage2 (stage2), base 0x80018a80
 * address 0x80070474  body 0x80070474..0x800704df  size 108 B
 * body sha256 29fd9131b76ca329d525964f0fa3d0c34fb03fdd9dcd414904a06f6e82f361db
 * provider record sha256 575d6330d295ef1b1d2d60190460c1666c313576df09304647b82a5e91a45755
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_80070474(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_800704e0(*(undefined4 *)(param_1 + 0x154),
                       *(undefined1 *)(*(int *)(param_1 + 0x1c) + 2));
  FUN_8006e838(*(undefined1 *)(*(int *)(param_1 + 0x1c) + 1),uVar1,
               (int)(short)(&DAT_800e8c78)[*(byte *)(*(int *)(param_1 + 0x1c) + 3)]);
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 4;
  return 1;
}
