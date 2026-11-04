/* FUN_80165d10
 * image   ovl_00b321e (ovl), base 0x80161cf0
 * address 0x80165d10  body 0x80165d10..0x80165d9f  size 144 B
 * body sha256 ff22ce0f1115efc6d2f2dbc4763f27aa28e906bc4c8e1fb29be35b38cc7694ba
 * provider record sha256 8550190dac29a4e2283ca59a610631c4e5ca7f888a96235541d18a9f42c335cf
 * callees 2 direct (2 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165d10(undefined4 param_1,int param_2)

{
  char cVar1;
  
  if (*(char *)(param_2 + 7) == '\0') {
    *(undefined1 *)(param_2 + 1) = 0xc;
  }
  FUN_80165ea0(param_1,param_2);
  cVar1 = *(char *)(param_2 + 1);
  *(char *)(param_2 + 1) = cVar1 + -1;
  if (cVar1 == '\x01') {
    *(byte *)(param_2 + 9) = *(byte *)(param_2 + 9) & 0x7f;
  }
  FUN_80165bd0(param_1,3,(int)*(short *)(param_2 + 2),0);
  FUN_80165bd0(param_1,4,(int)*(short *)(param_2 + 4),0);
  return;
}
