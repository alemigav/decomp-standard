/* FUN_80165364
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80165364  body 0x80165364..0x801654cf  size 364 B
 * body sha256 04fb2e60cb7ff282a1cc0f7f0aed7be512247fc0fa61d5984f34aef04fdbcc8f
 * provider record sha256 336d8e7309b0c031486443227f3cc31f02b72f8f667c810782951c8d4eb2a821
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165364(int param_1)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + 0x2cd) = 0;
  switch(*(undefined1 *)(param_1 + 0x2cc)) {
  case 2:
  case 3:
    uVar1 = 1;
    goto LAB_80165474;
  case 4:
    FUN_801655f4(param_1);
    break;
  case 5:
  case 6:
    uVar1 = 1;
    goto LAB_80165474;
  case 7:
    FUN_80165b98(param_1,4);
    break;
  case 8:
    FUN_80165b98(param_1,6);
    break;
  case 9:
  case 10:
  case 0x10:
  case 0x11:
  case 0x13:
    FUN_80165a44(param_1,5,4);
    FUN_80165dc4(param_1,0x17,0x60,0x60,0x60);
    break;
  case 0xb:
    FUN_80165dc4(param_1,0x17,0x60,0x60,0x60);
    FUN_80165a44(param_1,4,9);
    break;
  case 0xd:
    uVar1 = 1;
    goto LAB_80165474;
  case 0xe:
    FUN_80165dc4(param_1,0x17,0x60,0x60,0x60);
    FUN_80165cb8(param_1);
    break;
  case 0xf:
    uVar1 = 1;
    goto LAB_80165474;
  case 0x12:
    uVar1 = 4;
LAB_80165474:
    FUN_801654d0(param_1,uVar1,0,6,0x2800,0);
  }
  return;
}
