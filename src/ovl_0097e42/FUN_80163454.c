/* FUN_80163454
 * image   ovl_0097e42 (ovl), base 0x80161cf0
 * address 0x80163454  body 0x80163454..0x801634c7  size 116 B
 * body sha256 654d1ddeff100eecbcf9971dc7993b762e885e5db8038f7c2a398d8dc00272a4
 * provider record sha256 1de6fc1bb4c0d7ad37fa0f93def30fd42cd6e061fc082d62b246f3f33744a415
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80163454(int param_1)

{
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined4 *)(param_1 + 0x1e8) = 0xf000000;
    func_0x80077adc(0x4000001,param_1 + 0x28);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  func_0x80089d54(param_1,*(undefined4 *)(param_1 + 0x22c),*(undefined4 *)(param_1 + 0x230),0x400);
  return;
}
