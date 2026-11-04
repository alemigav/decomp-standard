/* FUN_8006dbc0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8006dbc0  body 0x8006dbc0..0x8006dbf3  size 52 B
 * body sha256 f9f0a340bf3e002c543ddbed7ba5e2f29342462a0063a64ee21be3a283715368
 * provider record sha256 17442640a18373628334bce814bbab72fe16babd6c9a9f0854190b59afb73057
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
undefined4 FUN_8006dbc0(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(iVar3 + 1);
  uVar2 = *(undefined1 *)(iVar3 + 3);
  *(int *)(param_1 + 0x1c) = iVar3 + 4;
  FUN_8006d628(uVar1,uVar2);
  return 1;
}
