/* FUN_80165b44
 * image   ovl_0098ee0 (ovl), base 0x80161cf0
 * address 0x80165b44  body 0x80165b44..0x80165c4f  size 268 B
 * body sha256 a29662fd0862196d10581d58fc4c79e29c99e313396ad76dbb2a4c6f29f32547
 * provider record sha256 f22ee6ecf6e26030104535dcec0aa5a1bd45a8eff6822f793ff19ebb84b4a57e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80165b44(uint *param_1)

{
  char cVar1;
  
  switch(*(undefined1 *)((int)param_1 + 7)) {
  case 0:
    func_0x80035b84(param_1);
    *(undefined2 *)(param_1 + 0x9c) = 0;
    *(byte *)((int)param_1 + 0x26f) = *(byte *)((int)param_1 + 0x26f) | 0x80;
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    *(ushort *)((int)param_1 + 0x1aa) = *(ushort *)((int)param_1 + 0x1aa) | 0x4000;
  case 1:
    cVar1 = func_0x80036c68(param_1,10,0xf,0);
    goto LAB_80165c34;
  case 2:
    *param_1 = *param_1 | 2;
    if (*(short *)(param_1 + 0x9c) != 0) {
      *(undefined2 *)(param_1 + 0x9c) = 0;
      *(undefined1 *)((int)param_1 + 7) = 3;
    }
    break;
  case 3:
    *(undefined1 *)((int)param_1 + 0x1e9) = 0;
    func_0x80036b84(param_1,0xb,0,0);
    if (*(short *)(param_1 + 0x9c) != 0) {
      *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + '\x01';
    }
    break;
  case 4:
    cVar1 = func_0x80036b84(param_1,0xb,0,0);
LAB_80165c34:
    *(char *)((int)param_1 + 7) = *(char *)((int)param_1 + 7) + cVar1;
  }
  return;
}
