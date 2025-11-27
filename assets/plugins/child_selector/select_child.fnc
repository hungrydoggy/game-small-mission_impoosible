%Envelope%:
  val:
    '~selectChild':
      '''{(GameComponent* self, ,,, vector<Var> msg_params)
        auto name = msg_params[0].as<string>();

        for (int ci=0; ci<self->getChildCount(); ++ci) {
          auto chl = self->getChild(ci);
          unlikely (chl == null)
            continue;

          chl->is_drawable_self(chl->name() == name);
        }
      '''
