/* FUN_80166a30
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80166a30  body 0x80166a30..0x80166b53  size 292 B
 * body sha256 a7f0f6c94ca4bad445cfb0195d851499a700a0a2fcbabcc82c5401f3760c1204
 * provider record sha256 33c158f95563ee4d00f127410809a8e557cd1384efea5697219d9f0dad0c8ef7
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166a30(int param_1)

{
  int iVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  uVar5 = *(undefined4 *)(param_1 + 0x1a4);
  uVar4 = *(undefined4 *)(param_1 + 0x218);
  if (*(char *)(param_1 + 6) == '\0') {
    *(undefined1 *)(param_1 + 6) = 1;
    *(undefined2 *)(param_1 + 0x1e0) = 600;
    uVar3 = (uint)*(byte *)(param_1 + 5);
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    *(uint *)(param_1 + 0x1e8) = (uVar3 + 3) * 0x1000000 + 0xf00;
    if (uVar3 == 0) {
      *(undefined2 *)(param_1 + 500) = 0x800;
    }
    else {
      *(undefined2 *)(param_1 + 500) = 0;
    }
    func_0x80077adc(((uVar3 & 1) + 1) * 0x10000 | 0x4000001,param_1 + 0x28);
  }
  else if (*(char *)(param_1 + 6) != '\x01') {
    return;
  }
  iVar1 = func_0x80089d54(param_1,uVar5,uVar4,0x100);
  if (iVar1 != 0) {
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) & 0xfe;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  }
  func_0x80032b5c(param_1,(int)*(short *)(param_1 + 500) - (int)*(short *)(param_1 + 0x66));
  uVar2 = *(short *)(param_1 + 0x1e0) - 0x5a;
  *(ushort *)(param_1 + 0x1e0) = uVar2;
  if ((int)((uint)uVar2 << 0x10) < 0) {
    *(undefined2 *)(param_1 + 0x1e0) = 0;
  }
  return;
}
